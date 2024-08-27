#include <iostream>

using namespace std;

// Function to compute the Fibonacci number at a given position
int fib(unsigned long long int);

int main(void)
{
    int n;
    cin >> n; // Input the position in the Fibonacci sequence
    
    cout << fib(n) << endl; // Print the Fibonacci number at position n
}

// Function to compute the Fibonacci number at a given position
// @param broj: the position in the Fibonacci sequence (0-based index)
// @return: the Fibonacci number at the specified position
int fib(unsigned long long int broj)
{
    if (broj < 2) // Base cases: F(0) = 1 and F(1) = 1
        return 1;
    else
        return fib(broj - 1) + fib(broj - 2); // Recursive call to compute Fibonacci number
}
