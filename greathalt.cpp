// #include "greathalt.h"

// class FloorPlan;
// class ParkingSlot;

// int main()
// {
// }
#include "greathalt.h"
// #include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <vector>
#include <rapidjson/document.h>
 
struct User {
    std::string loginname;
    std::string pwSHA256ChkSum;
    std::string role;
};
 
std::vector<User> readUserData(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonData = buffer.str();
    rapidjson::Document document;
    document.Parse(jsonData.c_str());
    std::vector<User> users;
    for (auto& item : document.GetArray()) {
        User user;
        user.loginname = item["loginname"].GetString();
        user.pwSHA256ChkSum = item["pwSHA256ChkSum"].GetString();
        user.role = item["role"].GetString();
        users.push_back(user);
    }
    return users;
}
std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}
bool authenticateUser(const std::vector<User>& users, const std::string& loginname, const std::string& password, std::string& role) {
    std::string hashedPassword = sha256(password);
    for (const auto& user : users) {
        if (user.loginname == loginname && user.pwSHA256ChkSum == hashedPassword) {
            role = user.role;
            return true;
        }
    }
    return false;
}
 
 
int main() {
    string dataFile = "UserData.json";
    UserType userType = authenticate(dataFile);
 
    switch (userType) {
        case admin:
            cout << "Access granted. Role: Admin" << endl;
            break;
        case user:
            cout << "Access granted. Role: User" << endl;
            break;
        case invalid:
        default:
            cout << "Invalid credentials" << endl;
            break;
    }
 
    return 0;
}