#include <iostream>

using namespace std;

// Function that recursively prints numbers starting from a given number, incremented by a fixed step, until a limit is reached
void zmurke(int, int);

int main()
{
    int x;
    cin >> x; // Input the limit number from the user

    zmurke(5, x); // Call the function starting from 5 and up to the limit x
    return 0;
}

// Function that recursively prints numbers starting from a given number, incremented by a fixed step, until a limit is reached
// @param broj: the current number to be printed and incremented
// @param limit: the upper limit to stop the recursion
void zmurke(int broj, int limit)
{
    cout << broj << endl; // Print the current number
    if (broj == limit) // If the current number equals the limit
        return; // End recursion
    else
        return zmurke(broj + 5, limit); // Recursive call with the number incremented by 5
}
