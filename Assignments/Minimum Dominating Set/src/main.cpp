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

    // Find the Min Dominating Set
    time(&start);           // Start the timer
    int bestSolution = graph.findMinimumSolution();
    time(&finish);          // Finish the timer

    // Print out the vector
    std::cout << "Best Solution = " << bestSolution << std::endl;

    // Compute the amount of time required
    std::cout << "Time required = " << difftime(finish, start) << " seconds";

    return 0;

}

