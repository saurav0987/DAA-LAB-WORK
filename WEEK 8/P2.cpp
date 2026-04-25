#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int parent[100], rankArr[100];

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int px = find(x), py = find(y);
    if(rankArr[px] < rankArr[py])
        parent[px] = py;
    else if(rankArr[px] > rankArr[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rankArr[px]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices (cities): ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):" << endl;
    for(int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    for(int i = 0; i < V; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
    cout << "Edge\tWeight" << endl;
    int totalCost = 0, edgeCount = 0;
    for(auto &e : edges) {
        if(find(e.u) != find(e.v)) {
            cout << e.u << " - " << e.v << "\t" << e.weight << endl;
            totalCost += e.weight;
            unionSets(e.u, e.v);
            edgeCount++;
        }
        if(edgeCount == V - 1) break;
    }
    cout << "Minimum Spanning Cost: " << totalCost << endl;
    return 0;
}
