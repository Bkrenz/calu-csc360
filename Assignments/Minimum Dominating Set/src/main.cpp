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
#include <time.h>
#include <math.h>
#include <vector>
#include "graph.hpp"

const int SIZE = 24;
const float DENSITY = 30;

int main() {

    // Init
    srand(time(NULL));
    time_t start, finish;

    // Create an Undirected Graph
    Graph graph = Graph(SIZE, DENSITY);
    graph.generateRandomGraph();

    // Print out the graph
    std::cout << graph.toString() << std::endl;

    // Find the Minimum Dominating Set
    time(&start);           // Start the timer
    int* bestSolution = graph.findMinimumSolution();
    time(&finish);          // Finish the timer

    // Output the minimum set
    std::cout << "The minimum dominating is: \n{";
    for (int i = 0; i < SIZE - 1; i++)
    {
        std::cout << std::to_string(bestSolution[i]) << ", ";
    }
    std::cout << std::to_string(bestSolution[SIZE-1]) << "}" << std::endl;

    // Output the amount of time required
    std::cout << "Time required: " << difftime(finish, start) << " seconds" << std::endl << std::endl;

    // Find the Approximate Solution
    time(&start);           // Start the timer
    int* approximateSolution = graph.findApproximateSolution();
    time(&finish);          // Finish the timer

    // Output the minimum set
    std::cout << "The minimum dominating is: \n{";
    for (int i = 0; i < SIZE - 1; i++)
    {
        std::cout << std::to_string(approximateSolution[i]) << ", ";
    }
    std::cout << std::to_string(approximateSolution[SIZE-1]) << "}" << std::endl;

    // Output the amount of time required
    std::cout << "Time required: " << difftime(finish, start) << " seconds" << std::endl;

    // Exit the program
    return 0;

}

