#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m, n;
    string a, b;
    cin >> a >> b; // Input the two strings
    n = a.size(); // Length of the first string
    m = b.size(); // Length of the second string
    int mat[n+1][m+1]; // DP table to store LCS lengths
    cout << endl;

    // Initialize the DP table with zeros
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            mat[i][j] = 0;
        }
    }

    // Fill the DP table
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(a[i-1] == b[j-1]) // Characters match
            {
                mat[i][j] = mat[i-1][j-1] + 1; // Extend the LCS
            }
            else // Characters do not match
            {
                // Choose the maximum LCS length from either excluding current character from string a or b
                if(mat[i-1][j] > mat[i][j-1])
                    mat[i][j] = mat[i-1][j];
                else
                    mat[i][j] = mat[i][j-1];
            }
        }
    }

    // Output the DP table
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Output the length of the longest common subsequence
    cout << endl << mat[n][m] << endl;
}
