#include <iostream>
#include <iomanip>

using namespace std;

// Function to find the minimum temperature from a series of inputs
// @param n: the number of temperature values to be input
// @param minimalna: reference to the variable where the minimum temperature will be stored
void temperatura(int n, int& minimalna);

int main(void)
{
    int n, minimalna = INT_MAX; // Initialize minimalna to the maximum possible integer value
    cin >> n; // Input the number of temperature values

    temperatura(n, minimalna); // Call the function to find the minimum temperature

    cout << minimalna; // Print the minimum temperature
    return 0;
}

// Recursive function to find the minimum temperature
// @param n: the number of temperature values remaining to be input
// @param minimalna: reference to the variable where the minimum temperature is updated
void temperatura(int n, int& minimalna)
{
    int broj = 0;

    if (n > 0) // If there are more temperature values to process
    {
        cin >> broj; // Input the next temperature value
        if (broj < minimalna) // Update the minimum temperature if the current value is smaller
            minimalna = broj;
        return temperatura(n - 1, minimalna); // Recursive call to process the next temperature value
    }
}
