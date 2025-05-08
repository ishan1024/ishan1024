#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int start, vector<bool>& visited, int depth, int maxDepth) {
        if (depth > maxDepth) return;

        visited[start] = true;
        cout << "Node " << start << " at depth " << depth << endl;

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, depth + 1, maxDepth);
            }
        }
    }

    void DFS(int start, int maxDepth) {
        vector<bool> visited(V, false);
        DFS(start, visited, 0, maxDepth);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    int maxDepth = 2;
    cout << "DFS starting from node 0 with max depth " << maxDepth << ": " << endl;
    g.DFS(0, maxDepth);
    cout << endl;

    return 0;
}
