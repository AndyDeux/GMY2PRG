#include <iostream>
#include <iomanip>
using namespace std;

// Function that recursively prints numbers from `broj1` to `broj2` in steps of `inter`
// @param inter: the interval or step size for incrementing
// @param broj1: the starting number
// @param broj2: the ending number
void interval(double inter, double broj1, double broj2);

int main(void)
{
    double n, a, b;
    
    cin >> n >> a >> b; // Input the interval, start, and end values
    
    n /= 10; // Adjust the interval by dividing it by 10
    interval(n, a, b); // Call the function with the adjusted interval, start, and end values
}

// Function that recursively prints numbers from `broj1` to `broj2` in steps of `inter`
// @param inter: the interval or step size for incrementing
// @param broj1: the starting number
// @param broj2: the ending number
void interval(double inter, double broj1, double broj2)
{
    if (broj1 == broj2) // If the current number equals the ending number
    {
        cout << setprecision(5) << fixed << broj2 << endl; // Print the ending number with fixed precision
        return; // End recursion
    }
    else
    {
        cout << setprecision(5) << fixed << broj1 << endl; // Print the current number with fixed precision
        return interval(inter, broj1 + inter, broj2); // Recursive call with the current number incremented by the interval
    }
}
