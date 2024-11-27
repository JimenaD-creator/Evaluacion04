#include <iostream>
#include "UserManager.h"
#include <stdexcept>
using namespace std;

void UserManager::addUser(const string& name){
    if(userInterests.find(name) == userInterests.end()){
        userInterests[name] = unordered_set<string>();
    }
}

void UserManager::addInterest(const string& name, const string& interest){
    auto it = userInterests.find(name);
    if(it == userInterests.end()){
        throw invalid_argument("Usuario no encontrado");

    }
    it -> second.insert(interest);
}
vector <string> UserManager::getInterests(const string& name){
    auto it = userInterests.find(name);
    if(it == userInterests.end()){
        throw invalid_argument("Usuario no encontrado");
    }
    return vector<string>(it->second.begin(), it->second.end());
}
