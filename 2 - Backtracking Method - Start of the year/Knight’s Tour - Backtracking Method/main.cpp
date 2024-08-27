#include <iostream>
#include <iomanip>

using namespace std;

const int N = 8; // Size of the chessboard (8x8 for Knight's Tour)

// Function declarations
int isSafe(int, int, int[][N]); // Function to check if a move is safe
void printSolution(int[][N]); // Function to print the solution
int solveKT(void); // Function to solve the Knight's Tour problem
bool solveKTUtil(int, int, int, int[][N], int[], int[]); // Recursive utility function to solve the problem

int main()
{
    solveKT(); // Solve the Knight's Tour problem

    return 0;
}

/**
 * Checks if the next move is within bounds and the position is not yet visited.
 * @param x - X coordinate of the next position
 * @param y - Y coordinate of the next position
 * @param sol - Current solution matrix
 * @return true if the move is safe, otherwise false
 */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/**
 * Prints the solution matrix of the Knight's Tour.
 * @param sol - Solution matrix to be printed
 */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << " " << setw(2) << sol[i][j] << " "; // Print the solution matrix
        }
        cout << endl;
    }
}

/**
 * Solves the Knight's Tour problem using backtracking.
 * Initializes the solution matrix and starts the recursive utility function.
 * @return 0 if no solution exists, otherwise prints the solution
 */
int solveKT()
{
    int sol[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = -1; // Initialize the solution matrix with -1 (unvisited)
        }
    }
    int xmove[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // Possible moves in x direction
    int ymove[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // Possible moves in y direction
    sol[0][0] = 0; // Start from the initial position

    if (!solveKTUtil(0, 0, 1, sol, xmove, ymove))
    {
        cout << "Solution does not exist\n"; // If no solution exists
    }
    else
    {
        printSolution(sol); // Print the solution if it exists
    }
}

/**
 * Recursive utility function to solve the Knight's Tour problem.
 * Tries all possible moves from the current position.
 * @param x - Current x coordinate
 * @param y - Current y coordinate
 * @param movei - Current move number
 * @param sol - Solution matrix
 * @param xmove - Array of possible x moves
 * @param ymove - Array of possible y moves
 * @return true if solution is found, otherwise false
 */
bool solveKTUtil(int x, int y, int movei, int sol[N][N], int xmove[8], int ymove[8])
{
    int k, next_x, next_y;

    if (movei == N * N)
    {
        return true; // If all cells are visited
    }

    for (k = 0; k < 8; k++) {
        next_x = x + xmove[k];
        next_y = y + ymove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei; // Make the move
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xmove, ymove)) {
                return true; // If the move leads to a solution
            } else {
                sol[next_x][next_y] = -1; // Backtrack
            }
        }
    }
    return false; // No solution found for this move
}
