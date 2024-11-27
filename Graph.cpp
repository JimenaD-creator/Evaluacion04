#include "Graph.h"


 void Graph::addEdge(const string& user, const string& user2) {
        Lista[user].push_back(user2);
        Lista[user2].push_back(user);
        cout << "Conexion entre " << user << " y " << user2 << endl;
    }


void Graph::BFS(const string& user){
        if (Lista.find(user) == Lista.end()) {
            cout << "Usuario " << user << " NO ENCONTRADO" << endl;
            return;
        }

        unordered_map<string, bool> visited;
        queue<string> Visitar;
        visited[user] = true;
        Visitar.push(user);

        cout << "AMIGOS DE " << user << ": ";
        while (!Visitar.empty()) {
            string current = Visitar.front();
            Visitar.pop();


            for (const string& nombre : Lista[current]) {
                if (!visited[nombre]) {
                    visited[nombre] = true;
                    toVisit.push(nombre);
                    cout << nombre << " ";
                }
            }
        }
        cout << endl;
    }
