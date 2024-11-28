#include "Graph.h"


 void Graph::addEdge(const string& user, const string& user2) {
        Lista[user].push_back(user2);
        Lista[user2].push_back(user);
        cout << "Conexion entre " << user << " y " << user2 << endl;
    }


vector <string> Graph::BFS(const string& user){
        vector<string>friends;
        if (Lista.find(user) == Lista.end()) {
            cout << "Usuario " << user << " no encontrado " << endl;
            return friends;
        }

        unordered_map<string, bool> visited;
        queue<string> Visitar;
        visited[user] = true;
        Visitar.push(user);

        cout << "AMIGOS DE " << user << ": "<<endl;
        while (!Visitar.empty()) {
            string current = Visitar.front();
            Visitar.pop();


            for (const string& nombre : Lista[current]) {
                if (!visited[nombre]) {
                    visited[nombre] = true;
                    Visitar.push(nombre);
                    cout << nombre << " ";
                    friends.push_back(nombre);
                }
            }
        }
        return friends;
    }
