#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NEPOZNATO = 0; // Represents an empty cell in the Sudoku grid
const int N = 9; // Size of the Sudoku grid (9x9)

// Function declarations
void ucitajPocetniSudoku(int[][N]); // Function to load the initial Sudoku grid from a file
bool resiSudoku(int[][N]); // Function to solve the Sudoku puzzle
bool pronadjiPraznoPolje(int[][N], int&, int&); // Function to find an empty cell in the grid
bool isSafe(int[][N], int, int, int); // Function to check if a number can be safely placed in a cell
bool postojiURedu(int[][N], int, int); // Function to check if a number exists in the row
bool postojiUKoloni(int[][N], int, int); // Function to check if a number exists in the column
bool postojiUKvadratu(int[][N], int, int, int); // Function to check if a number exists in the 3x3 sub-grid
void ispisiReseniSudoku(int[][N]); // Function to print the solved Sudoku grid

int main(void)
{
    int m[N][N]; // Sudoku grid

    ucitajPocetniSudoku(m); // Load the initial Sudoku grid from a file

    if (resiSudoku(m) == true)
        ispisiReseniSudoku(m); // Print the solved Sudoku grid
    else
        cout << "\nNo solution exists\n"; // Print message if no solution is found

    return 0;
}

/**
 * Loads the initial Sudoku grid from a file.
 * @param m - 2D array representing the Sudoku grid
 */
void ucitajPocetniSudoku(int m[][N])
{
    string imeFajla;
    cout << "\nEnter the filename containing the initial Sudoku grid:";
    cin >> imeFajla;

    ifstream ulaz(imeFajla);
    if (ulaz.is_open())
    {
        for (int red = 0; red < N; ++red)
            for (int kolona = 0; kolona < N; ++kolona)
                ulaz >> m[red][kolona];

        ulaz.close();
    }
    else
        for (int red = 0; red < N; ++red)
            for (int kolona = 0; kolona < N; ++kolona)
                m[red][kolona] = NEPOZNATO; // Set all cells to empty if file cannot be opened
}

/**
 * Solves the Sudoku puzzle using backtracking.
 * @param m - 2D array representing the Sudoku grid
 * @return true if the puzzle is solved, otherwise false
 */
bool resiSudoku(int m[][N])
{
    int red, kolona;
    if (!pronadjiPraznoPolje(m, red, kolona))
        return true; // No empty cells left, puzzle is solved

    for (int broj = 1; broj <= N; ++broj)
    {
        if (isSafe(m, red, kolona, broj))
        {
            m[red][kolona] = broj;

            if (resiSudoku(m))
                return true; // Continue solving recursively

            m[red][kolona] = NEPOZNATO; // Backtrack
        }
    }
    return false; // No solution found, backtrack
}

/**
 * Finds the next empty cell in the Sudoku grid.
 * @param m - 2D array representing the Sudoku grid
 * @param red - Row index of the found empty cell
 * @param kolona - Column index of the found empty cell
 * @return true if an empty cell is found, otherwise false
 */
bool pronadjiPraznoPolje(int m[][N], int& red, int& kolona)
{
    for (red = 0; red < N; red++)
        for (kolona = 0; kolona < N; ++kolona)
            if (m[red][kolona] == NEPOZNATO)
                return true; // Empty cell found
    return false; // No empty cells found
}

/**
 * Checks if placing a number in a specific cell is valid.
 * @param m - 2D array representing the Sudoku grid
 * @param red - Row index of the cell
 * @param kolona - Column index of the cell
 * @param broj - Number to be placed in the cell
 * @return true if placing the number is valid, otherwise false
 */
bool isSafe(int m[][N], int red, int kolona, int broj)
{
    return !postojiURedu(m, red, broj) // Check row
        && !postojiUKoloni(m, kolona, broj) // Check column
        && !postojiUKvadratu(m, red - red % 3, kolona - kolona % 3, broj) // Check 3x3 sub-grid
        && m[red][kolona] == NEPOZNATO; // Check if cell is empty
}

/**
 * Checks if a number exists in a specific row.
 * @param m - 2D array representing the Sudoku grid
 * @param red - Row index
 * @param broj - Number to be checked
 * @return true if the number exists in the row, otherwise false
 */
bool postojiURedu(int m[][N], int red, int broj)
{
    for (int kolona = 0; kolona < N; ++kolona)
        if (m[red][kolona] == broj)
            return true; // Number found in row
    return false; // Number not found in row
}

/**
 * Checks if a number exists in a specific column.
 * @param m - 2D array representing the Sudoku grid
 * @param kolona - Column index
 * @param broj - Number to be checked
 * @return true if the number exists in the column, otherwise false
 */
bool postojiUKoloni(int m[][N], int kolona, int broj)
{
    for (int red = 0; red < N; ++red)
        if (m[red][kolona] == broj)
            return true; // Number found in column
    return false; // Number not found in column
}

/**
 * Checks if a number exists in a specific 3x3 sub-grid.
 * @param m - 2D array representing the Sudoku grid
 * @param kvadratPocetniRed - Starting row index of the sub-grid
 * @param kvadratPocetnaKolona - Starting column index of the sub-grid
 * @param broj - Number to be checked
 * @return true if the number exists in the sub-grid, otherwise false
 */
bool postojiUKvadratu(int m[][N], int kvadratPocetniRed, int kvadratPocetnaKolona, int broj)
{
    for (int red = 0; red < 3; ++red)
        for (int kolona = 0; kolona < 3; ++kolona)
            if (m[red + kvadratPocetniRed][kolona + kvadratPocetnaKolona] == broj)
                return true; // Number found in sub-grid
    return false; // Number not found in sub-grid
}

/**
 * Prints the solved Sudoku grid to a file. If the file cannot be opened, prints to the console.
 * @param m - 2D array representing the solved Sudoku grid
 */
void ispisiReseniSudoku(int m[][N])
{
    ofstream izlaz("sudokuResenje.txt");
    if (izlaz.is_open())
    {
        for (int red = 0; red < N; ++red)
        {
            if (red % 3 == 0)
                izlaz << endl; // Separate 3x3 sub-grids
            for (int kolona = 0; kolona < N; ++kolona)
            {
                if (kolona % 3 == 0)
                    izlaz << " "; // Separate 3x3 sub-grids
                izlaz << " " << m[red][kolona] << " ";
            }
            izlaz << endl;
        }
        izlaz.close();
    }
    else
    {
        for (int red = 0; red < N; ++red)
        {
            if (red % 3 == 0)
                cout << endl; // Separate 3x3 sub-grids
            for (int kolona = 0; kolona < N; ++kolona)
            {
                if (kolona % 3 == 0)
                    cout << " "; // Separate 3x3 sub-grids
                cout << " " << m[red][kolona] << " ";
            }
            cout << endl;
        }
    }
}
