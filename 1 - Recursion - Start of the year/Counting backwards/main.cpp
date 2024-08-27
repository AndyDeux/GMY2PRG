#include <iostream>

using namespace std;

// Function that recursively prints numbers from the given value down to zero
void unazad(unsigned long long int);

int main(void)
{
    int n;
    cin >> n; // Input a number from the user
    
    unazad(n); // Call the function to print numbers backwards
    cout << " " << endl; // Print a blank line for better readability
}

// Function that recursively prints numbers from the given number down to zero
// @param broj: the current number to be printed and from which to start decrementing
void unazad(unsigned long long int broj)
{
    if (broj != 0) { // If the number is not zero
        cout << broj << endl; // Print the current number
        return unazad(broj - 1); // Recursive call with the number decreased by 1
    } else if (broj == 0) { // If the number is zero
        cout << 0 << endl; // Print zero
    }
}
