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

        std::string toString();

        int* findMinimumSolution();
        int* findApproximateSolution();
    
    private:
        int size;
        int density;
        int** adjacencyMatrix;

        void generateRandomGraph();

};

#endif