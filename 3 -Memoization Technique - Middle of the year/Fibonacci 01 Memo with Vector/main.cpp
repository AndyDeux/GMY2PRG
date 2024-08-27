#include <iostream>
#include <vector>

using namespace std;

// Function to compute Fibonacci number without memoization
unsigned long long int fib(unsigned long long int);

// Function to compute Fibonacci number with memoization
unsigned long long int fib(unsigned long long int, vector<unsigned long long int>&);

int main(void)
{
    unsigned long long int n;
    cin >> n;
    
    // Compute and print the Fibonacci number for input n
    cout << fib(n) << endl;
}

// Function to initialize memoization vector and call the main Fibonacci function
unsigned long long int fib(unsigned long long int broj)
{
    // Create a memoization vector with (broj + 1) elements, initialized to 0
    vector<unsigned long long int> memo(broj + 1);
    fill(memo.begin(), memo.end(), 0);
    
    // Call the Fibonacci function with memoization
    return fib(broj, memo);
}

// Function to compute Fibonacci number using memoization
unsigned long long int fib(unsigned long long int broj, vector<unsigned long long int>& memo)
{
    // If the value is already computed, return it from memoization vector
    if(memo.at(broj) > 0)
        return memo.at(broj);
    // Base case: Fibonacci number for 0 or 1 is 1
    else if(broj < 2)
        return memo.at(broj) = 1;
    // Recursive case: Compute Fibonacci number using memoization
    else
        return memo.at(broj) = fib(broj - 1, memo) + fib(broj - 2, memo);
}
