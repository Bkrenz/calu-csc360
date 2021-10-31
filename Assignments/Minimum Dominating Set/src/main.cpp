/** *
 * 
 * Author: Frank Bedekovich
 * Author: Robert Krency
 * Author: Regina Thase 
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <math.h>
#include <vector>
#include "graph.hpp"

const int SIZE = 24;
const float DENSITY = 30;

int main() {

    // Init
    srand(time(NULL));

    // Create an Undirected Graph
    Graph graph = Graph(SIZE, DENSITY);

    // Print out the graph
    std::cout << graph.toString() << std::endl;

    // Find the Minimum Dominating Set
    auto start = std::chrono::steady_clock::now();
    int* bestSolution = graph.findMinimumSolution();
    auto finish = std::chrono::steady_clock::now();

    // Output the minimum set
    std::cout << "The minimum dominating is: \n{";
    for (int i = 0; i < SIZE - 1; i++)
    {
        std::cout << std::to_string(bestSolution[i]) << ", ";
    }
    std::cout << std::to_string(bestSolution[SIZE-1]) << "}" << std::endl;

    // Output the amount of time required
    std::chrono::duration<double> elapsed_seconds = finish-start;
    std::cout << "Time required: " << elapsed_seconds.count() << " seconds" << std::endl << std::endl;

    // Find the Approximate Solution
    start = std::chrono::steady_clock::now();
    int* approximateSolution = graph.findApproximateSolution();
    finish = std::chrono::steady_clock::now();

    // Output the approximate set
    std::cout << "The approximate solution is: \n{";
    for (int i = 0; i < SIZE - 1; i++)
    {
        std::cout << std::to_string(approximateSolution[i]) << ", ";
    }
    std::cout << std::to_string(approximateSolution[SIZE-1]) << "}" << std::endl;

    // Output the amount of time required
    elapsed_seconds = finish-start;
    std::cout << "Time required: " << elapsed_seconds.count() << " seconds" << std::endl;

    // Exit the program
    return 0;

}

