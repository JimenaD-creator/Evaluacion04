#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H
#include "UserManager.h"
#include "ContentManager.h"
#include "Graph.h"

using namespace std;

class RecommendationSystem {
private:
    UserManager userManager;
    ContentManager contentManager;
    Graph graph;

public:
    void addUser(const string& name);
    void addContent(const string& category, const string& content);
    void addFriend(const string& user1, const string& user2);
    void addInterest(const string& name, const string& interest);
    vector<string> recommendContent(vector<string> friends); // Declaración del método
};

#endif
