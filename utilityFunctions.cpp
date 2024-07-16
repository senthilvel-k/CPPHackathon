#include "utilityFunctions.h"
#include "greathalt.h"


string SHA256(string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

Document parseJsonFromFile(const string& filename) {
    FILE* fp = fopen(filename.c_str(), "rb");
    char readBuffer[65536]; 
    FileReadStream is(fp, readBuffer, sizeof(readBuffer)); 

    Document doc;
    doc.ParseStream(is);

    fclose(fp); 
    return doc; 
}


enum UserType authenticate(string dataFile) {

   Document doc = parseJsonFromFile(dataFile);

    string loginId;
    string password;

    cout << "Please enter your login ID: ";
    cin >> loginId;
    cout << "Please enter your password: ";
    cin >> password;

    string hashedPassword = SHA256(password);
    const Value& usersArray = doc["Users"];

    for (SizeType i = 0; i < usersArray.Size(); i++) {
        const Value& users = usersArray[i];
        if (users.IsObject() && users.HasMember("loginname") && users.HasMember("pwSHA256ChkSum")) {
            if (users["loginname"].IsString() && users["pwSHA256ChkSum"].IsString()) {
                if (users["loginname"].GetString() == loginId && users["pwSHA256ChkSum"].GetString() == hashedPassword) {
                    if (users.HasMember("role") && users["role"].IsString() && strcmp(users["role"].GetString(), "admin") == 0) {
                        return admin;
                    } else {
                        return user;
                    }
                }
            }
        }
    }

    return invalid;
}

