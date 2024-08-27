#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    cin >> k; // Number of elements in the combination
    cin >> n; // Maximum number that can be used in the combinations

    // Vector for dynamic programming
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Initialization: There is 1 way to form a combination with 0 elements
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Filling the DP table
    for (int i = 1; i <= n; ++i) { // Iterate through all numbers from 1 to n
        for (int j = 1; j <= k; ++j) { // Iterate through all possible combination sizes
            // If we do not use the number i, the number of combinations is the same as for i-1
            dp[i][j] = dp[i-1][j];
            // If we use the number i, add the number of combinations for i-1 and j-1
            if (j > 0) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    // Output the number of different possible combinations
    cout << "Number of different possible combinations is: " << dp[n][k] << endl;

    return 0;
}
