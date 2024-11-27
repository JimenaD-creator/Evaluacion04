#ifndef GRAPH_H
#define GRAPH_H


class Graph
{
    public:
       vector<vector<int>> addEdge(string user1,string user2,vector<vector<int>> matrix, vector<vector<string>> users);
       
       void BFS(string user,vector<vector<int>> matrix, vector<vector<string>> users);
       

    protected:

    private:
};

#endif // GRAPH_H
