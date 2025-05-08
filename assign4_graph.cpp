#include <iostream>
#include <vector>
using namespace std;

const int MAXV = 100; // Maximum number of vertices
vector<int> graph[MAXV];
int color[MAXV];

// Check if it's safe to color vertex v with c
bool isSafe(int v, int c, int V) {
    for (int neighbor : graph[v]) {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

// Recursive backtracking function to color the graph
bool graphColoring(int v, int V, int m) {
    if (v == V) return true; // All vertices colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, V)) {
            color[v] = c; // Assign color
            if (graphColoring(v + 1, V, m))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false; // No color could be assigned
}

int main() {
    int V, E, m;
    cout << "Enter number of vertices, edges, and colors: ";
    cin >> V >> E >> m;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected graph
    }

    for (int i = 0; i < V; i++) color[i] = 0;

    if (graphColoring(0, V, m)) {
        cout << "\nColor assignment:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " ---> Color " << color[i] << "\n";
        }
    } else {
        cout << "\nNo solution exists with " << m << " colors.\n";
    }

    return 0;
}
