#include "GraphNode.h"

// Constructor
GraphNode::GraphNode(int id) : id(id) {}

// Add a neighbor and its capacity
void GraphNode::addNeighbor(int neighborId, int capacity) {
    neighbors[neighborId] = capacity;
}
