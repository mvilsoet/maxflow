#include "Graph.h"
#include <queue>
#include <climits>    // INT_MAX
#include <algorithm>  // std::min()

// Constructor
Graph::Graph(int n) {
    // Initialize the residual capacity matrix with size n x n and all values set to 0
    residualCapacity = vector<vector<int>>(n, vector<int>(n, 0));
    
    // Add GraphNode objects to the 'nodes' vector
    for (int i = 0; i < n; ++i) {
        GraphNode newNode(i); // GraphNode with ID 'i'
        nodes.push_back(newNode); // Add node to the nodes
        // nodes.emplace_back(i);  // "The arguments `args...` are forwarded to the [object's] constructor.."
    }
}

// Add an edge with a capacity
void Graph::addEdge(int from, int to, int capacity) {
    nodes[from].addNeighbor(to, capacity);
    residualCapacity[from][to] = capacity; // Set initial residual capacity
}

// BFS to find an augmenting path
bool Graph::bfs(int source, int sink, vector<int>& parent) {
    int n = nodes.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const auto& [neighbor, capacity] : nodes[current].neighbors) {  // Get reference to each neighbor of current
            if (!visited[neighbor] && residualCapacity[current][neighbor] > 0) {
                parent[neighbor] = current;
                visited[neighbor] = true;
                q.push(neighbor);

                if (neighbor == sink) return true;
            }
        }
    }
    return false;
}

// Edmonds-Karp to calculate maximum flow
int Graph::edmondsKarp(int source, int sink) {
    int n = nodes.size();
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(source, sink, parent)) {
        int pathFlow = INT_MAX;

        // Find the minimum capacity along the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualCapacity[u][v]);
        }

        // Update residual capacities along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualCapacity[u][v] -= pathFlow;
            residualCapacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}
