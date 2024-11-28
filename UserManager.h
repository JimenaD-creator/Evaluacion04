
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class UserManager{
    private:
    //Mapa para almacenar usuarios y sus intereses
    unordered_map <string, unordered_set<string>> userInterests;

    public:
    void addUser(const string& name);
    void addInterest(const string &name, const string& interest);
    vector <string> getInterests(const string& name);
    bool userExists(const string& user);



};

#endif // USERMANAGER_H
