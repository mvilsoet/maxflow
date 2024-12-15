#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <vector>
using namespace std;

class Graph {
private:
    vector<GraphNode> nodes; // List of nodes in the graph
    vector<vector<int>> residualCapacity; // Residual graph

public:
    Graph(int n); // Constructor
    void addEdge(int from, int to, int capacity); // Add an edge
    int edmondsKarp(int source, int sink); // Calculate maximum flow using Edmonds-Karp

private:
    bool bfs(int source, int sink, vector<int>& parent); // Find an augmenting path
};

#endif
