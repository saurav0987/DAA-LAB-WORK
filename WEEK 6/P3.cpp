#include<iostream>
#include<vector>
using namespace std;

int V;
vector<vector<int>> adj;

bool dfs(int node, vector<int> &visited) {
    visited[node] = 1;
    for(int neighbor : adj[node]) {
        if(visited[neighbor] == 1)
            return true;
        if(visited[neighbor] == 0)
            if(dfs(neighbor, visited))
                return true;
    }
    visited[node] = 2;
    return false;
}

bool hasCycle() {
    vector<int> visited(V, 0);
    for(int i = 0; i < V; i++) {
        if(visited[i] == 0)
            if(dfs(i, visited))
                return true;
    }
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    adj.resize(V);
    int e;
    cout << "Enter number of directed edges: ";
    cin >> e;
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if(hasCycle())
        cout << "Cycle exists in the directed graph" << endl;
    else
        cout << "No cycle exists in the directed graph" << endl;
    return 0;
}
