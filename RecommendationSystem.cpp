#include "RecommendationSystem.h"
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;


void RecommendationSystem::addUser(const string& name) {
    userManager.addUser(name);
}


void RecommendationSystem::addContent(const string& category, const string& content) {
    contentManager.addContent(category, content);
}


void RecommendationSystem::addFriend(const string& user1, const string& user2) {
    graph.addEdge(user1, user2); // Crear relación de amistad bidireccional
}


void RecommendationSystem::addInterest(const string& name, const string& interest) {
    userManager.addInterest(name, interest);
}


vector<string> RecommendationSystem::recommendContent(vector<string> friends) {

    cout << "Número de amigos: " << friends.size() << endl;


    unordered_set<string> friendsInterests;

    for (const string& friendUser : friends) {

        if (!userManager.userExists(friendUser)) {
            cout << "Usuario no encontrado: " << friendUser << endl;
            continue;
        }


        vector<string> interests = userManager.getInterests(friendUser);
        cout << "Intereses del usuario " << friendUser << ": ";
        for (const string& interest : interests) {
            cout << interest << " ";
        }
        cout << endl;

        friendsInterests.insert(interests.begin(), interests.end());
    }


    unordered_set<string> recommendedContent;

    for (const string& interest : friendsInterests) {

        vector<string> contents = contentManager.getContentByCategory(interest);
        cout << "Contenido para el interés " << interest << ": ";
        for (const string& content : contents) {
            cout << content << " ";
        }
        cout << endl;

        recommendedContent.insert(contents.begin(), contents.end());
    }


    return vector<string>(recommendedContent.begin(), recommendedContent.end());
}
