#include <iostream>
#include "UserManager.h"
#include <stdexcept>
using namespace std;

void UserManager::addUser(string& name){
    if(userInterests.find(name) == userInterests.end()){
        userInterests[name] = unordered_set<string>();
    }
}

void UserManager::addInterest(string& name, string& interest){
    auto it = userInterests.find(name);
    if(it == userInterests.end()){
        throw invalid_argument("Usuario no encontrado");

    }
    it -> second.insert(interest);
}
vector <string> UserManager::getInterests(string& name){
    auto it = userInterests.find(name);
    if(it == userInterests.end()){
        throw invalid_argument("Usuario no encontrado");
    }
    return vector<string>(it->second.begin(), it->second.end());
}
