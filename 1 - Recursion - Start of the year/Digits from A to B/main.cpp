#include <iostream>

using namespace std;

// Function that recursively prints numbers between two given values
void ab(int, int);

int main()
{
    int a;
    cin >> a; // Input the first number from the user

    int b;
    cin >> b; // Input the second number from the user

    ab(a, b); // Call the function to print numbers between a and b
    return 0;
}

// Function that recursively prints numbers between two given values
// @param broj1: the first number
// @param broj2: the second number
void ab(int broj1, int broj2)
{
    if (broj1 >= broj2) { // If the first number is greater than or equal to the second number
        cout << broj2 << endl; // Print the second number
        if (broj1 == broj2) // If the numbers are equal
            return; // End recursion
        else
            return ab(broj2 + 1, broj1); // Recursive call with the second number incremented by 1
    } else { // If the first number is less than the second number
        cout << broj1 << endl; // Print the first number
        if (broj1 == broj2) // If the numbers are equal
            return; // End recursion
        else
            return ab(broj1 + 1, broj2); // Recursive call with the first number incremented by 1
    }
}
