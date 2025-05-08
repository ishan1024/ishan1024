#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unite(int u, int v) {
        int uRoot = find(u);
        int vRoot = find(v);
        if (uRoot != vRoot) {
            if (rank[uRoot] < rank[vRoot])
                parent[uRoot] = vRoot;
            else if (rank[uRoot] > rank[vRoot])
                parent[vRoot] = uRoot;
            else {
                parent[vRoot] = uRoot;
                rank[uRoot]++;
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter " << E << " edges in format: u v weight\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    vector<Edge> mst;
    int totalWeight = 0;

    for (auto& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            ds.unite(edge.u, edge.v);
        }
    }

    cout << "\nEdges in MST:\n";
    cout << "Edge \tWeight\n";
    for (auto& edge : mst)
        cout << edge.u << " - " << edge.v << "\t" << edge.weight << "\n";
    cout << "Total weight of MST: " << totalWeight << "\n";

    return 0;
}
