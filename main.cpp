#include <iostream>
#include "Graph.h"

int main() {
    int numNodes = 8; 
    Graph graph(numNodes);

    // Satellite to Regions
    graph.addEdge(0, 1, 15);  // S -> R1
    graph.addEdge(0, 2, 10);  // S -> R2
    graph.addEdge(0, 3, 12);  // S -> R3
    
    // Regions to Peers
    graph.addEdge(1, 4, 8);   // R1 -> P1
    graph.addEdge(1, 5, 7);   // R1 -> P2
    
    graph.addEdge(2, 5, 5);   // R2 -> P2
    graph.addEdge(2, 6, 6);   // R2 -> P3
    
    graph.addEdge(3, 6, 4);   // R3 -> P3
    graph.addEdge(3, 7, 9);   // R3 -> P4
    
    // Peers to Sink
    graph.addEdge(4, 8, 10);  // P1 -> T
    graph.addEdge(5, 8, 8);   // P2 -> T
    graph.addEdge(6, 8, 7);   // P3 -> T
    graph.addEdge(7, 8, 6);   // P4 -> T
    
    // Inter-Peer connections
    graph.addEdge(4, 6, 3);   // P1 -> P3
    graph.addEdge(5, 7, 5);   // P2 -> P4

    int source = 0;  // Satellite/Source node
    int sink = 8;    // Sink node

    std::cout << "Maximum Flow: " << graph.edmondsKarp(source, sink) << std::endl;

    return 0;
}