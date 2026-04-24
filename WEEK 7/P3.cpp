#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int V, E;

struct Edge {
    int u, v, weight;
};

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):" << endl;
    for(int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    int src, dest, k;
    cout << "Enter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;
    cout << "Enter number of edges (k): ";
    cin >> k;
    vector<vector<int>> dp(k + 1, vector<int>(V, INT_MAX));
    dp[0][src] = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].weight;
            if(dp[i - 1][u] != INT_MAX && dp[i - 1][u] + w < dp[i][v])
                dp[i][v] = dp[i - 1][u] + w;
        }
    }
    if(dp[k][dest] == INT_MAX)
        cout << "No path from " << src << " to " << dest << " with exactly " << k << " edges" << endl;
    else
        cout << "Shortest path weight from " << src << " to " << dest << " with exactly " << k << " edges: " << dp[k][dest] << endl;
    return 0;
}
