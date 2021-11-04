/** *
 * 
 * Author: Frank Bedekovich
 * Author: Robert Krency
 * Author: Regina Thase 
 * 
 * 
 * This program finds the minimum dominating set of a graph.
 * When started it has an optional group of 3 arguments that can be passed.
 * All or none must be declared, in the following order, as integers.
 *      - start-size
 *      - max-size
 *      - iterations
 * When no arguments put in, default values are listed in code below.
 * If invalid number of arguments entered, an error is output and program exits.
 * 
 * See paper for experimental data on runtimes.
 * 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <math.h>
#include <vector>
#include "graph.hpp"

// Default values
const int MAX_SIZE = 20;        // The amount of vertices in the graph
const float DENSITY = 30;       // The density percentage of the graph
const float ITERATIONS = 5;     // The amount of iterations to run

int main(int argc, char **argv) {

    // Init
    srand(time(NULL));
    int size = MAX_SIZE;
    int maxSize = MAX_SIZE;
    int iterations = ITERATIONS;
    std::chrono::duration<double> elapsed_seconds;
    std::string fileName;
    std::ofstream out;
    bool redirectOut = true;

    // Parse the Command Line Args
    //      Arg 0 - prog name
    //      Arg 1 - Starting Size
    //      Arg 2 - Max Size
    //      Arg 3 - Iterations
    if (argc == 4)
    {
        size = atoi(argv[1]);
        maxSize = atoi(argv[2]);
        iterations = atoi(argv[3]);
    }
    else if (argc > 1)
    {
        std::cout << "Invalid numbers of arguments.";
        return 0;
    }
    else 
        redirectOut = false;
    
    if (redirectOut)
    {
        // Redirect cout to the appropriate file
        fileName = "min-dominating-set.txt";
        out.open(fileName);
        std::cout.rdbuf(out.rdbuf());
    }

    // Setup the table headings
    std::cout << "Graph Density: " << DENSITY << "%" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(12) << "Verts"; 
    std::cout << std::setw(12) << "Min Size";
    std::cout << std::setw(12) << "Min Time";
    std::cout << std::setw(12) << "App Size";
    std::cout << std::setw(12) << "App Time";
    std::cout << std::endl << std::endl;

    // Iterate the Algorithm multiple times
    for(; size <= maxSize; size++)
    {
        
        // Run the algorithm
        for(int x = 1; x <= iterations; x++)
        {

            // Print out the graph size
            std::cout << std::setw(12) << size;

            // Create an Undirected Graph
            Graph graph = Graph(size, DENSITY);

            // Find the Minimum Dominating Set
            auto start = std::chrono::steady_clock::now();
            std::set<int> bestSolution = graph.findMinimumSolution();
            auto finish = std::chrono::steady_clock::now();

            // Output the minimum set
            std::cout << std::setw(12) << bestSolution.size();
            elapsed_seconds = finish-start;
            std::cout << std::setw(12) << elapsed_seconds.count();

            // Find the Approximate Solution
            start = std::chrono::steady_clock::now();
            std::set<int> approximateSolution = graph.findApproximateSolution();
            finish = std::chrono::steady_clock::now();

            // Output the approximate set
            std::cout << std::setw(12) << approximateSolution.size();
            elapsed_seconds = finish-start;
            std::cout << std::setw(12) << elapsed_seconds.count();
        
            std::cout << std::endl;
        }

    }

    // Close the file
    if(redirectOut)
        out.close();

    // Exit the program
    return 0;

}

