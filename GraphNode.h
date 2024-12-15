#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <unordered_map>
#include <vector>
using namespace std;

class GraphNode {
public:
    int id; // Unique identifier for the node
    unordered_map<int, int> neighbors; // Adjacent nodes and their capacities

    GraphNode(int id); // Constructor
    void addNeighbor(int neighborId, int capacity); // Add a neighbor with a capacity
};

#endif
