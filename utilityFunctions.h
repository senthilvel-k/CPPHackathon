#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H


#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <openssl/sha.h>
#include <iostream>
#include <string>


using namespace std;
using namespace rapidjson;

enum UserType { user, admin, invalid } ;

string SHA256(string str);

enum UserType authenticate(string dataFile);

#endif