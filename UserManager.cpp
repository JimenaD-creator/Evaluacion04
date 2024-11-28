#include <iostream>
#include "UserManager.h"
#include <stdexcept>
using namespace std;

bool UserManager::userExists(const string& user) {

    return userInterests.find(user) != userInterests.end();
}

void UserManager::addUser(const string& name){
    if (userExists(name)) {
        cout << "El usuario " << name << " ya existe." << endl;
        return;
    }
    userInterests[name] = unordered_set<string>(); // Agregar usuario vacío inicialmente
    cout << "Usuario " << name << " agregado correctamente." << endl;
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
