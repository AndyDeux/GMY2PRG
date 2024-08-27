#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Dimensions of the grid
const int dim = 8;

// Declaration of the function that uses the Trimini algorithm to fill the grid
void Trimini(int[][dim], int, int, int, int, int, int&);

int main(void)
{
    // Randomly select the initial cell to be filled
    srand(time(NULL));
    int v = rand() % dim;  // Random row index
    int k = rand() % dim;  // Random column index
    
    // Allocate the matrix where results will be written
    int tabla[dim][dim];
    
    // Initialize the starting cell
    int broj = 0;
    tabla[v][k] = broj++;
    
    // Recursive function fills the rest of the grid
    Trimini(tabla, dim, 0, 0, v, k, broj);
    
    // Print the resulting grid
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout << " " << (char)('a' + tabla[i][j]);
        }
        cout << endl;
    }
    return 0;
}

// Function that uses the Trimini algorithm to fill the square grid
void Trimini(int tabla[][dim], int dimenzija, int v0, int k0, int v, int k, int& broj)
{
    // If the dimension of the square is 1x1 and only one cell is filled, the square is already completely filled
    if(dimenzija > 1) {
        int vsred1 = v0 + dimenzija / 2 - 1;
        int vsred2 = v0 + dimenzija / 2;
        int ksred1 = k0 + dimenzija / 2 - 1;
        int ksred2 = k0 + dimenzija / 2;
        
        // Determine which quadrant contains the existing hole
        bool holeTopLeft = v <= vsred1 && k <= ksred1;
        bool holeBottomLeft = v >= vsred2 && k <= ksred1;
        bool holeTopRight = v <= vsred1 && k >= ksred2;
        bool holeBottomRight = v >= vsred2 && k >= ksred2;
        
        // Place numbers in the center of each quadrant
        if (!holeTopLeft)
            tabla[vsred1][ksred1] = broj;
        if (!holeBottomLeft)
            tabla[vsred2][ksred1] = broj;
        if (!holeTopRight)
            tabla[vsred1][ksred2] = broj;
        if (!holeBottomRight)
            tabla[vsred2][ksred2] = broj;
        
        broj++;
        
        // Recursively fill each quadrant
        if (holeTopLeft)
            Trimini(tabla, dimenzija / 2, v0, k0, v, k, broj);
        else
            Trimini(tabla, dimenzija / 2, v0, k0, v, k, broj);
        
        if (holeBottomLeft)
            Trimini(tabla, dimenzija / 2, vsred2, k0, v, k, broj);
        else
            Trimini(tabla, dimenzija / 2, vsred2, k0, vsred2, ksred1, broj);
        
        if (holeTopRight)
            Trimini(tabla, dimenzija / 2, v0, ksred2, v, k, broj);
        else
            Trimini(tabla, dimenzija / 2, v0, ksred2, vsred1, ksred2, broj);
        
        if (holeBottomRight)
            Trimini(tabla, dimenzija / 2, vsred2, ksred2, v, k, broj);
        else
            Trimini(tabla, dimenzija / 2, vsred2, ksred2, vsred2, ksred2, broj);
    }
}
