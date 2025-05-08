#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

class Graph {
    int V;
    vector<vector<pii>> adj; // adjacency list: adj[u] = vector of (weight, v)

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u}); // For undirected graph
    }

    void primMST() {
        vector<int> key(V, INT_MAX);  // Minimum weight to reach each vertex
        vector<int> parent(V, -1);    // To store the MST
        vector<bool> inMST(V, false); // To mark vertices included in MST

        priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
        key[0] = 0;
        pq.push({0, 0}); // (key, vertex)

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto& [weight, v] : adj[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        // Print MST
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; ++i)
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}
