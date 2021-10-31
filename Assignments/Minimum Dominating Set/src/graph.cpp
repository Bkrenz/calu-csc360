/***
 * 
 * Author: Frank Bedekovich
 * Author: Robert Krency
 * Author: Regina Thase
 * 
 */

#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.hpp"

#include <string>
#include <math.h>
#include <stdlib.h>

const int SIZE = 16;
const int DENSITY = 30;


Graph::Graph()
{
    this->size = SIZE;
    this->density = DENSITY;
    this->generateRandomGraph();
}


Graph::Graph(const int pSize, const int pDensity)
{
    this->size = pSize;
    this->density = pDensity;
    this->generateRandomGraph();
}


Graph::~Graph()
{
    for (int i = 0; i < this->size; i++)
        delete [] this->adjacencyMatrix[i];
    delete [] this->adjacencyMatrix;
}


void Graph::generateRandomGraph()
{
    int value;

    // Setup the 2D array for the Adjacency Matrix
    this->adjacencyMatrix = new int*[this->size];
    for (int i = 0; i < this->size; i++)
        this->adjacencyMatrix[i] = new int[this->size];

    // Loop through all rows
    for (int i = 0; i < this->size; i++)
    {
        // Loop through all columns, use j=i to go down the diagonals
        for (int j = i; j < this->size; j++)
        {
            // Randomise a connection based on density probability
            value = (rand() % 100 < this->density || j == i) ? 1 : 0;

            // Add the connection to the adjacency matrix for both values
            this->adjacencyMatrix[i][j] = value;
            this->adjacencyMatrix[j][i] = value;
        }
    }
}


int* Graph::findMinimumSolution()
{


    return 0;
}


int* Graph::findApproximateSolution()
{
    return 0;
}


std::string Graph::toString()
{
    std::string output = "";

    // Graph Size and Density
    output += "Size: " + std::to_string(this->size) + " \n";
    output += "Density: "  + std::to_string(this->density) + "\n";
    output += "\n";

    // Print out the adjacency Matrix
    output += "Adjacency Matrix:\n";
    for (int i = 0; i < this->size; i++)
    {
        for(int j = 0; j < this->size; j++)
            output += std::to_string(this->adjacencyMatrix[i][j]) + " ";
        output+= "\n";
    }
    output += "\n";

    return output;
}

#endif