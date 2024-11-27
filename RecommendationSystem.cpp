#include "RecommendationSystem.h"
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;


void RecommendationSystem::addUser(const string& user) {
    userManager.addUser(user);
}


void RecommendationSystem::addContent(const string& category, const string& content) {
    contentManager.addContent(category, content);
}


void RecommendationSystem::addFriend(const string& user1, const string& user2) {
    graph.addEdge(user1, user2); // Crear relación de amistad bidireccional
}


void RecommendationSystem::addInterest(const string& user, const string& interest) {
    userManager.addInterest(user, interest);
}


vector<string> RecommendationSystem::recommendContent(const string& user) {

    vector<string> friends = graph.BFS(user);


    unordered_set<string> friendsInterests;

    for (const string& friendUser : friends) {
        vector<string> interests = userManager.getInterests(friendUser);
        friendsInterests.insert(interests.begin(), interests.end());
    }


    unordered_set<string> recommendedContent;


    for (const string& interest : friendsInterests) {
        vector<string> contents = contentManager.getContentByCategory(interest);
        recommendedContent.insert(contents.begin(), contents.end());
    }


    return vector<string>(recommendedContent.begin(), recommendedContent.end());
}
