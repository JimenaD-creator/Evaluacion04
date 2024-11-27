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
    void addUser(string& name);
    void addInterest(string &name, string& interest);
    vector <string> getInterests(string& name);

};