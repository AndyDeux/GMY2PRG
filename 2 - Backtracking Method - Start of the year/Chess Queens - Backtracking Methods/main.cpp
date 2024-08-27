#include <iostream>
#include <cmath>

const int brojDama = 4; // Number of queens (4 in this example)

// Function declarations
bool ok(int b[], int n); // Function to check if the current queen position is valid
void dodajDamu(int b[], int n); // Recursive function to place queens on the board
void ispisiRasporedDama(int b[]); // Function to print the queen arrangement

using namespace std;

int main()
{
    int tabla[brojDama]; // Initialize the board (array) with 4 positions
    dodajDamu(tabla, 0); // Start the recursion with the first queen

    return 0;
}

/**
 * Checks if the current arrangement of queens is valid (i.e., queens do not attack each other).
 * @param b - Array representing the current arrangement of queens on the board
 * @param n - Index of the queen currently being placed
 * @return true if all queens placed so far are in valid positions, otherwise false
 */
bool ok(int b[], int n) {
    for (int i = 0; i < n; i++) { // Check queens from 0 to n-1
        // Queens attack each other if they are in the same column or on the same diagonal
        if (b[i] == b[n] || (n - i) == abs(b[n] - b[i]))
            return false; // Return false if queens attack each other
    }
    return true; // All queens are in valid positions
}

/**
 * Recursive function that attempts to place queens on the board.
 * @param b - Array representing the current arrangement of queens on the board
 * @param n - Index of the queen currently being placed
 */
void dodajDamu(int b[], int n) {
    if (n == brojDama) { // If all queens are placed
        ispisiRasporedDama(b); // Print the valid arrangement
    } else {
        for (int i = 0; i < brojDama; i++) { // Iterate through all possible positions in the column
            b[n] = i; // Place the queen in the current position
            if (ok(b, n)) // Check if the position is valid
                dodajDamu(b, n + 1); // If valid, try to place the next queen
        }
    }
}

/**
 * Prints the current arrangement of queens on the board.
 * @param b - Array representing the arrangement of queens
 */
void ispisiRasporedDama(int b[]) {
    static int z = 0; // Solution counter
    cout << "Solution number " << ++z << endl;
    for (int j = 0; j < brojDama; j++) {
        cout << b[j] << endl; // Print the position of the queen in each column
    }
    cout << "Done!" << endl << endl;
}
