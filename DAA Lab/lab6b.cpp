#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

// Function to compute the minimum cost of matrix chain multiplication
int matrixMultiplication(int dimensions[], int n) {
    // Create a dp table to store minimum multiplication costs
    int dp[n][n];

    // Initialize the dp table. The diagonal is already zero because no
    // multiplication cost is required for a single matrix.
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the dp table
    // len is the length of the subproblem chain
    for (int len = 2; len < n; len++) { // len is the length of the subproblem chain
        for (int s = 0; s < n - len; s++) { // s is the starting index of the subchain
            int e = s + len; // e is the ending index of the subchain
            int minCost = INT_MAX; // Start with a very large value

            // Try every possible position to split the chain
            for (int k = s + 1; k < e; k++) {
                // Calculate the cost of splitting at position k
                int cost = dp[s][k] + dp[k][e] + dimensions[s] * dimensions[k] * dimensions[e];
                minCost = min(minCost, cost); // Update the minimum cost
            }

            dp[s][e] = minCost; // Store the minimum cost in the dp table
        }
    }

    // Return the minimum cost for multiplying the entire matrix chain
    return dp[0][n - 1];
}

int main() {
    // Define the dimensions of the matrices (chain)
    int dimensions[] = {3, 1, 5, 8}; // Example matrix dimensions
    int n = sizeof(dimensions) / sizeof(dimensions[0]);

    // Calculate and print the minimum cost to multiply the matrices
    cout << "Minimum cost to multiply the matrices: "
         << matrixMultiplication(dimensions, n) << endl;

    return 0;
}
