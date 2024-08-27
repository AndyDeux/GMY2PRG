#include <iostream>
#include <cmath>

const int brojDama = 4; // Constant number of queens (4 in this case)

// Function declarations
void ispisiRasporedDama(int[]); // Function to print the arrangement of queens
bool jeValidnoResenje(int[]); // Function to check if the current arrangement is valid

using namespace std;

int main() {
    int tabla[brojDama]; // Array to hold the positions of the queens

    // Brute force approach: Try all possible combinations of queen placements
    for (int i = 0; i < brojDama; i++) {
        for (int j = 0; j < brojDama; j++) {
            for (int k = 0; k < brojDama; k++) {
                for (int l = 0; l < brojDama; l++) {
                    tabla[0] = i; // Place the first queen in row 0
                    tabla[1] = j; // Place the second queen in row 1
                    tabla[2] = k; // Place the third queen in row 2
                    tabla[3] = l; // Place the fourth queen in row 3
                    
                    // Check if the current arrangement is valid
                    if (jeValidnoResenje(tabla)) {
                        ispisiRasporedDama(tabla); // Print the valid arrangement
                    }
                }
            }
        }
    }

    return 0;
}

/**
 * Checks if the current arrangement of queens is valid.
 * @param b - Array representing the current arrangement of queens on the board
 * @return true if the arrangement is valid, otherwise false
 */
bool jeValidnoResenje(int b[]) {
    for (int i = 0; i < brojDama; i++) {
        for (int j = i + 1; j < brojDama; j++) {
            // Check if queens are in the same column or on the same diagonals
            if (b[i] == b[j] || abs(b[j] - b[i]) == j - i) {
                return false; // Return false if queens attack each other
            }
        }
    }
    return true; // All queens are in valid positions
}

/**
 * Prints the current arrangement of queens on the board.
 * @param b - Array representing the arrangement of queens
 */
void ispisiRasporedDama(int b[]) {
    static int resenjeBroj = 0; // Solution counter
    cout << "Solution number " << ++resenjeBroj << ":" << endl;
    for (int i = 0; i < brojDama; i++) {
        cout << b[i] << " "; // Print the position of each queen in the current arrangement
    }
    cout << endl << endl;
}
