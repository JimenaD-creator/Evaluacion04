#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H
#include "ContentManager.h"
#include "Graph.h"
#include "UserManager.h"



using namespace std;

class RecommendationSystem {
private:
    UserManager userManager;
    ContentManager contentManager;
    Graph graph;

public:
    void addUser(const string& user);
    void addContent(const string& category, const string& content);
    void addFriend(const string& user1, const string& user2);
    void addInterest(const string& user, const string& interest);
    vector<string> recommendContent(const string& user); // Declaración del método
};

#endif
