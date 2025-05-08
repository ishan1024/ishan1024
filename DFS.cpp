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

    void DFS(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFS(start, visited);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS starting from node 0: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
