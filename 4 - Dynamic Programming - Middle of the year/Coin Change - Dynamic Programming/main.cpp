#include <iostream>
#include <limits>

using namespace std;

// Function to compute the minimum number of coins needed for a given amount
int novcici(int[], int, int);

int main(void)
{
    int novcici_niz[] = {1, 3, 5, 9}; // Array of available coin denominations
    
    int iznos;
    cin >> iznos; // Input the amount to be changed
    
    int duzina = sizeof(novcici_niz) / sizeof(novcici_niz[0]); // Number of coin denominations
    
    cout << "Broj novcica potreban za trazeni iznos je: " << novcici(novcici_niz, iznos, duzina) << endl;
    
}

// Function to compute the minimum number of coins needed for the given amount
int novcici(int novcici_niz[], int iznos, int duzina)
{
    int pomniz[iznos + 1]; // Array to store the minimum number of coins for each amount
    
    // Initialize the array with a large value representing infinity
    for (int i = 0; i < iznos + 1; i++) {
        pomniz[i] = INT_MAX;
    }
    pomniz[0] = 0; // Base case: 0 coins are needed for amount 0
    
    // Fill the array using dynamic programming
    for (int i = 1; i <= iznos; i++) {
        for (int j = 0; j < duzina; j++) {
            if (novcici_niz[j] <= i) {
                int potproblem = pomniz[i - novcici_niz[j]];
                
                // If the current coin can be used and results in fewer coins, update the array
                if (potproblem != INT_MAX && potproblem + 1 < pomniz[i]) {
                    pomniz[i] = potproblem + 1;
                }
            }
        }
    }
    // Return the minimum number of coins needed for the given amount
    return pomniz[iznos];
}
