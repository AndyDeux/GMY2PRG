#include <iostream>
#include <vector>

struct podatak
{
    bool izracunat; // Flag indicating whether the value has been computed
    unsigned long long int vrednost; // The computed Fibonacci number
};

using namespace std;

// Function to compute the Fibonacci number using a custom memoization structure
unsigned long long int fibonaci(unsigned long long int, vector<podatak>&);

int main(void)
{
    unsigned long long int n;
    cin >> n;

    // Initialize a vector of 'podatak' to store computed Fibonacci numbers
    vector<podatak> f(n + 1);
    
    // Initialize each element of the vector
    podatak x = {false, 0};
    fill(f.begin(), f.end(), x);

    // Compute and print the Fibonacci number for input n
    cout << fibonaci(n, f) << "\n\n";

    return 0;
}

// Function to compute Fibonacci number using a custom memoization structure
unsigned long long int fibonaci(unsigned long long int n, vector<podatak>& f)
{
    // If the value has already been computed, return it from the memoization structure
    if(f.at(n).izracunat)
        return f.at(n).vrednost;
    // Base case: For n < 2, the Fibonacci number is 1
    else if(n < 2)
    {
        f.at(n).izracunat = true;
        return f.at(n).vrednost = 1;
    }
    // Recursive case: Compute the Fibonacci number and store the result in the memoization structure
    else
    {
        f.at(n).vrednost = fibonaci(n - 1, f) + fibonaci(n - 2, f);
        f.at(n).izracunat = true;
        return f.at(n).vrednost;
    }
}
