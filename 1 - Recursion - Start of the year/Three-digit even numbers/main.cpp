#include <iostream>

using namespace std;

// Function that recursively prints even numbers between two given numbers
// @param broj1: the starting number (inclusive)
// @param broj2: the ending number (inclusive)
void tro(int broj1, int broj2);

int main(void)
{
    int a;
    cin >> a; // Input the first number
    
    int b;
    cin >> b; // Input the second number
    
    if (a < 100) {
        a = 100; // Set a to 100 if it is less than 100
    }
    
    if (b > 1000) {
        b = 998; // Set b to 998 if it is greater than 1000
    }
    
    a += a % 2; // Ensure a is even by adding 1 if it is odd
    b -= b % 2; // Ensure b is even by subtracting 1 if it is odd
    
    tro(a, b); // Call the function to print even numbers between a and b
    cout << " "; // Print a blank space for formatting
    return 0;
}

// Function that recursively prints even numbers from `broj1` to `broj2`
// @param broj1: the starting number (inclusive)
// @param broj2: the ending number (inclusive)
void tro(int broj1, int broj2)
{
    if (broj1 <= broj2) { // If the starting number is less than or equal to the ending number
        cout << broj1 << endl; // Print the current number
        return tro(broj1 + 2, broj2); // Recursive call with the next even number
    } else
        return; // End recursion if starting number exceeds the ending number
}
