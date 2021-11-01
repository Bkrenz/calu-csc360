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
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <math.h>
#include <vector>
#include "graph.hpp"

// Default values
const int MAX_SIZE = 24;        // The amount of vertices in the graph
const float DENSITY = 30;       // The density percentage of the graph
const float ITERATIONS = 1;     // The amount of iterations to run

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

    // Iterate the Algorithm multiple times
    for(; size <= maxSize; size++)
    {
        if (redirectOut)
        {
            // Redirect cout to the appropriate file
            fileName = "graph-size-" + std::to_string(size) + ".txt";
            out.open(fileName);
            std::cout.rdbuf(out.rdbuf());
        }

        // Print out the graph size
        std::cout << "# of Vertices: " << size << std::endl;
        
        // Run the algorithm
        for(int x = 1; x <= iterations; x++)
        {

            // Create an Undirected Graph
            Graph graph = Graph(size, DENSITY);

            // Output the iteration count
            std::cout << "Iteration " << x << ": " << std::endl;

            // Find the Minimum Dominating Set
            auto start = std::chrono::steady_clock::now();
            std::set<int> bestSolution = graph.findMinimumSolution();
            auto finish = std::chrono::steady_clock::now();

            // Output the minimum set
            std::cout << "The minimum dominating set is: { ";
            for (int i : bestSolution)
            {
                std::cout << i << ", ";
            }
            std::cout << "}. ";

            // Output the amount of time required
            elapsed_seconds = finish-start;
            std::cout << "Time required: " << elapsed_seconds.count() << " seconds" << std::endl;

            // Find the Approximate Solution
            start = std::chrono::steady_clock::now();
            std::set<int> approximateSolution = graph.findApproximateSolution();
            finish = std::chrono::steady_clock::now();

            // Output the approximate set
            std::cout << "The approximate solution is: { ";
            for (int i : approximateSolution)
            {
                std::cout << i << ", ";
            }
            std::cout << "}. ";

            // Output the amount of time required
            elapsed_seconds = finish-start;
            std::cout << "Time required: " << elapsed_seconds.count() << " seconds" << std::endl << std::endl;
        }

        // Close the file
        out.close();
    }

    // Exit the program
    return 0;

}

