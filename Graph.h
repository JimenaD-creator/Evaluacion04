#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Graph {
public:

    unordered_map<string, vector<string>> Lista;


    void addEdge(const string& user, const string& user2);


    void BFS(const string& user);
};



#endif // GRAPH_H
