#include "greathalt.h"
#include "rapidjson/filereadstream.h"
#include <openssl/sha.h>

string getSHA256 ( char *source );
string convertToHexString ( unsigned char* data, int dataSize ) ;
enum UserType authenticate(string dataFile)
{  
    string username, password;
    std::istringstream stream(dataFile);
    std::getline(stream, username);
    std::getline(stream, password);
    FILE* fp = fopen("UserData.json", "rb");
    if (!fp) {
        cerr << "Error opening file" << endl;
        return invalid;
    }
 
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document doc;
    doc.ParseStream(is);
    fclose(fp);
 
    if (doc.HasParseError()) {
        cerr << "Error parsing JSON" << endl;
        return invalid;
    }
 
    if (!doc.HasMember("Users") || !doc["Users"].IsArray()) {
        cerr << "Invalid JSON format" << endl;
        return invalid;
    }
 
    const rapidjson::Value& users = doc["Users"];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    string passwordHash = ss.str();
    for (auto& user : users.GetArray()) {
        if (user["loginname"].GetString() == username && user["pwSHA256ChkSum"].GetString() == passwordHash) {
            return (user["role"].GetString() == string("admin")) ? UserType::admin : UserType::user ;
        }
    }
    return invalid;
 
}
 
string getSHA256 ( char *source )
{
    const EVP_MD *md ;
    EVP_MD_CTX *mdctx ;
    unsigned int md_len, i ;
    unsigned char md_value[ EVP_MAX_MD_SIZE ] = "" ;
    string chksum ;
 
    OpenSSL_add_all_digests( ) ;
    md = EVP_get_digestbyname ( "SHA256" ) ;
    mdctx = EVP_MD_CTX_new( ) ;
    EVP_MD_CTX_init ( mdctx ) ;
    EVP_DigestInit_ex ( mdctx, md, NULL ) ;
    EVP_DigestUpdate ( mdctx, source, strlen ( source ) ) ;
    EVP_DigestFinal_ex ( mdctx, md_value, &md_len ) ;
    EVP_MD_CTX_free ( mdctx ) ;
    chksum = convertToHexString ( md_value, md_len ) ;
    return chksum ;
}
 string convertToHexString ( unsigned char* data, int dataSize )
{
    ostringstream oss ;
    oss << hex << setfill ( '0' ) ;
 
    for ( int i = 0 ; i < dataSize ; ++i )
        oss << setw( 2 ) << static_cast<unsigned int>( data[ i ] ) ;
 
    return oss.str( ) ;
}
