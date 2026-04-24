#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):" << endl;
    for(int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].weight;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    bool negCycle = false;
    for(int j = 0; j < E; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].weight;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            negCycle = true;
            break;
        }
    }
    if(negCycle) {
        cout << "Graph contains a negative weight cycle" << endl;
    } else {
        cout << "Vertex\tDistance from Source " << src << endl;
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX)
                cout << i << "\tINFINITY" << endl;
            else
                cout << i << "\t" << dist[i] << endl;
        }
    }
    return 0;
}
