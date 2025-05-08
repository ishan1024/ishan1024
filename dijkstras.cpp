#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

void printPath(int node, vector<int>& parent) {
    stack<int> path;
    while (node != -1) {
        path.push(node);
        node = parent[node];
    }
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V); // adjacency list

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // Remove this for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances and paths from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To vertex " << i << " (Distance: " << dist[i] << ") Path: ";
        if (dist[i] == INT_MAX) {
            cout << "No path";
        } else {
            printPath(i, parent);
        }
        cout << "\n";
    }

    return 0;
}
