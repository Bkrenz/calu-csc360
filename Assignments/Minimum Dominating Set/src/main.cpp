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

const int SIZE = 8;
const float DENSITY = 30;

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

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            std::cout << adjacencyMatrix[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < SIZE; i++)
        numbers[i] = conversion(adjacencyMatrix[i], SIZE);



    for (int i = 0; i < SIZE; i++)
    {
        std::cout << numbers[i] << std::endl;
    }

    // Find the Min Dominating Set
    int p = pow(2, SIZE - 1);
    time(&start);
    int neighbors;
    std::vector<int> solutions;
    for (int i = 0; i < p; i++ )
    {
        neighbors = 0;
        
        for (int j = 0; j < SIZE; j++)
        {
            if (i & (1 << j))
                neighbors = neighbors | numbers[j];
        }

        if (neighbors == p - 1)
            solutions.push_back(i);
    }
    time(&finish);

    // Print out the vector
    std::cout << "solutions = { ";
    for (int n : solutions) {
        std::cout << n << ", ";
    }
    std::cout << "}; \n";

    std::cout << "Time required = " << difftime(finish, start) << " seconds";

    return 0;

}

