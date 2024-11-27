#include "Graph.h"

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}
vector<vector<int>> addEdge(string user1,string user2,vector<vector<int>> matrix, vector<vector<string>> users){
 int x = find(users.begin(),user.end,user1);
       int y = find(users.begin(),user.end,user1);
       if(x==-1 || y==-1){
        cout<<"NO SE HA ENCONTRADO A UNO DE LOS USUARIOS"<<endl;
        return matrix;
       }
       else{
       matrix[x][y]=1;
       matrix[y][x]=1;
       cout<<"CONEXION CREADA"<<endl;
       }
       
       return matrix;
};

int BFS(int start, const vector<vector<int>>& adjacencyMatrix, const vector<vector<string>>& data) {
    int n = adjacencyMatrix.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (data[node][3] == targetDNA) {
            
        }


        for (int i = 0; i < n; i++) {
            if (adjacencyMatrix[node][i] != 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    return 0;
}

void BFS(string user,vector<vector<int>> matrix, vector<vector<string>> users){
int x = find(users.begin(),user.end,user1);
        if(x==-1){
        cout<<"NO ENCONTRADO"<<endl;
        return ;
       }
       
             int start = distance(users.begin(), it);
        vector<bool> visited(users.size(), false);
        queue<int> toVisit;

        visited[start] = true;
        toVisit.push(start);

        cout << "Amigos de " << user << ": ";
        while (!toVisit.empty()) {
            int current = toVisit.front();
            toVisit.pop();

            for (size_t i = 0; i < matrix[current].size(); ++i) {
                if (matrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    toVisit.push(i);
                    cout << users[i] << " ";
                }
            }
        }
        cout << endl;
        return;
    
};