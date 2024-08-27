#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n; // Input the size of the grid
    int m[n][n]; // Matrix to store the input values
    int ov[n][n]; // Matrix to store the maximum sums

    // Input the matrix values
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    // Initialize the maximum sums matrix with zeros
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ov[i][j] = 0;
        }
    }

    // Compute the maximum sum path
    ov[n-1][n-1] = m[n-1][n-1]; // Start from the bottom-right corner

    // Fill the last row (can only come from the right)
    for(int i = n-2; i >= 0; --i)
    {
        ov[i][n-1] = m[i][n-1] + ov[i+1][n-1];
    }

    // Fill the last column (can only come from below)
    for(int j = n-2; j >= 0; --j)
    {
        ov[n-1][j] = m[n-1][j] + ov[n-1][j+1];
    }

    // Fill the rest of the matrix
    for(int i = n-2; i >= 0; --i){
        for(int j = n-2; j >= 0; --j){
            // Choose the maximum sum path between moving right or down
            if(ov[i+1][j] > ov[i][j+1])
            {
                ov[i][j] = m[i][j] + ov[i+1][j];
            }
            else
            {
                ov[i][j] = m[i][j] + ov[i][j+1];
            }
        }
    }

    // Output the matrix of maximum sums
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ov[i][j] << " ";
        }
        cout << endl;
    }

    // Output the result for the top-left corner
    cout << endl << endl << "Resenje za Index [0][0] je " << ov[0][0] << endl << endl;
    return 0;
}
