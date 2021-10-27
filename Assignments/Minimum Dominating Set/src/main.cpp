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

const int SIZE = 30;
const float DENSITY = 30;


int getNextCombo(int combo);

int conversion(int array[], int len) {
    int output = 0;
    int power = 1;

    for (int i = 0; i < len; i++)
    {
        output += array[(len - 1) - i] * power;
        // output goes 1*2^0 + 0*2^1 + 0*2^2 + ...
        power *= 2;
    }

    return output;
}

int main() {

    // Init
    srand(time(NULL));
    time_t start, finish;

    // Create a Random Undirected Graph
    int adjacencyMatrix[SIZE][SIZE];
    int val;
    int numbers[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            val = (rand() % 100) < DENSITY || i == j ? 1 : 0;
            adjacencyMatrix[i][j] = val;
            adjacencyMatrix[j][i] = val;
        }
    }

    // Convert an array to an integer
    for (int i = 0; i < SIZE; i++)
        numbers[i] = conversion(adjacencyMatrix[i], SIZE);

    // Find the Min Dominating Set
    int p = pow(2, SIZE);   // The amount of combinations
    time(&start);           // Start the timer
    int neighbors, solution;
    for (solution = 0; solution < p; solution++)
    {
        neighbors = 0;
        
        for (int j = 0; j < SIZE; j++)
            if ((solution & (1 << j)) == (1 << j))
                neighbors = neighbors | numbers[j];

        if (neighbors == (p - 1))
            break; // Found a solution, but we're ending after finding the first solution, not necessarily the best solution
    }
    time(&finish);          // Finish the timer

    // Print out the vector
    std::cout << "solution = " << solution << std::endl;

    // Compute the amount of time required
    std::cout << "Time required = " << difftime(finish, start) << " seconds";

    return 0;

}

