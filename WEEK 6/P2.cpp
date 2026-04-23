#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V;
vector<vector<int>> adj;

bool isBipartite() {
    vector<int> color(V, -1);
    for(int start = 0; start < V; start++) {
        if(color[start] != -1) continue;
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neighbor : adj[node]) {
                if(color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if(color[neighbor] == color[node])
                    return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    adj.resize(V);
    int e;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartite())
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;
    return 0;
}
