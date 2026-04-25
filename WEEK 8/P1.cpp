#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int V;

int minKey(vector<int> &key, vector<bool> &inMST) {
    int minVal = INT_MAX, minIdx = -1;
    for(int v = 0; v < V; v++) {
        if(!inMST[v] && key[v] < minVal) {
            minVal = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void primMST(vector<vector<int>> &graph) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    key[0] = 0;
    for(int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST);
        inMST[u] = true;
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Edge\tWeight" << endl;
    int totalCost = 0;
    for(int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Minimum Cost to connect all cities: " << totalCost << endl;
}

int main() {
    cout << "Enter number of vertices (cities): ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 = no edge):" << endl;
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> graph[i][j];
    primMST(graph);
    return 0;
}
