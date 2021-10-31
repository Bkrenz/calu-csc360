/***
 * 
 * Author: Frank Bedekovich
 * Author: Robert Krency
 * Author: Regina Thase
 * 
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {

    public:
        Graph();
        Graph(const int pSize, const int pDensity);
        ~Graph();

        /**
         * toString() 
         * 
         * Constructs a formatted string with graph attributes and the adjacency
         * matrix representing the graph.
         */
        std::string toString();

        /**
         * findMinimumSolution() 
         * 
         * Finds the miminum dominating set of a graph. Checks all possible combinations
         * of vertices. Expected runtime: 2^n
         */
        int* findMinimumSolution();

        /** 
         * findApproximateSolution()
         * 
         * Finds an approximate solution of a minimal dominating set of a graph. This is
         * designed as a greedy algorithm that selects the vertex with the highest
         * out-degree as the next vertex for the dominating set.
         */
        int* findApproximateSolution();
    
    private:
        int size;
        int density;
        int** adjacencyMatrix;

        /**
         * generateRandomGraph() 
         * 
         * Generates a random adjacency matrix representing a graph. An undirected graph
         * is symmetrical along the main diagonal. All nodes are represented as having a
         * connection to themselves.
         * 
         */
        void generateRandomGraph();

};

#endif