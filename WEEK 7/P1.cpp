#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int V;

int minDistance(vector<int> &dist, vector<bool> &visited) {
    int minVal = INT_MAX, minIdx = -1;
    for(int v = 0; v < V; v++) {
        if(!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void dijkstra(vector<vector<int>> &graph, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;
    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    cout << "Vertex\tDistance from Source " << src << endl;
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX)
            cout << i << "\tINFINITY" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (" << V << "x" << V << ") (0 = no edge):" << endl;
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> graph[i][j];
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(graph, src);
    return 0;
}
