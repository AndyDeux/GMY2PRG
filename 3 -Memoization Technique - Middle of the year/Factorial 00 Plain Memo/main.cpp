#include <iostream>
#include <vector>

using namespace std;

// Function to compute factorial using memoization
unsigned long long int faktorijel(unsigned long long int n, vector<unsigned long long int>& f);

int main(void)
{
    int n;
    cin >> n;
    
    // Vector to store previously computed values
    vector<unsigned long long int> f(n+1);
    
    // Initialize all elements of the vector to 0
    fill(f.begin(), f.end(), 0);
    
    // Call the factorial function and print the result
    cout << faktorijel(n, f) << "\n\n";
}

// Function that uses memoization to compute factorial
unsigned long long int faktorijel(unsigned long long int n, vector<unsigned long long int>& f)
{
    // If the value is already computed, return it from memory
    if(f.at(n) > 0)
        return f.at(n);
    // Base case: factorial of 0 or 1 is 1
    else if(n <= 1)
        return f.at(n) = 1;
    // Recursive computation of factorial and storing the result in memory
    else
        return f.at(n) = n * faktorijel(n-1, f);
}
