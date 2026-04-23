#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;
int V;

void dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor])
            dfs(neighbor, visited);
    }
}

bool pathExists(int src, int dest) {
    vector<bool> visited(V, false);
    dfs(src, visited);
    return visited[dest];
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    adj.resize(V);
    int e;
    cout << "Enter number of edges: ";
    cin >> e;
    int isDirected;
    cout << "Is graph directed? (1=Yes, 0=No): ";
    cin >> isDirected;
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if(!isDirected)
            adj[v].push_back(u);
    }
    int src, dest;
    cout << "Enter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;
    if(pathExists(src, dest))
        cout << "Path exists between " << src << " and " << dest << endl;
    else
        cout << "No path exists between " << src << " and " << dest << endl;
    return 0;
}
