#include <iostream>
#include <vector>

using namespace std;

// Structure that holds two pieces of information: whether the value has been computed and the computed value
struct podatak {
    bool izracunat; // Indicates if the value has been computed (true or false)
    long long int vrednost; // Holds the computed value
};

// Function declarations
long long int funkcija(long long int); // Function that calls the memoized function
long long int funkcija(long long int, vector<podatak>&); // Memoized function

int main(void)
{
    long long int n;
    cin >> n; // Input number for which the function value is calculated

    cout << funkcija(n); // Print the result of the function for the given number
}

// Function to initialize the memoization vector and call the memoized function
long long int funkcija(long long int broj)
{
    vector<podatak> memo(broj + 1); // Memoization vector of size broj + 1
    podatak x = {false, 0}; // Initialize each element of the structure (izračunat = false, vrednost = 0)
    fill(memo.begin(), memo.end(), x); // Fill the vector with initial values

    return funkcija(broj, memo); // Call the memoized function
}

// Recursive function that uses memoization
long long int funkcija(long long int broj, vector<podatak>& memo)
{
    // If the value for the given number has already been computed, return the cached value
    if (memo.at(broj).izracunat == true)
        return memo.at(broj).vrednost;
    // Base case: If the number is 0, set the computed value to -1
    else if (broj == 0)
    {
        memo.at(broj).izracunat = true;
        return memo.at(broj).vrednost = -1;
    }
    // Base case: If the number is 1, set the computed value to 2
    else if (broj == 1)
    {
        memo.at(broj).izracunat = true;
        return memo.at(broj).vrednost = 2;
    }
    // For numbers between 2 and 10 (inclusive), use the formula: funkcija(broj-1) - 2*funkcija(broj-2)
    else if (broj >= 2 && broj <= 10)
    {
        memo.at(broj).izracunat = true;
        return memo.at(broj).vrednost = funkcija(broj-1, memo) - 2 * funkcija(broj-2, memo);
    }
    // For numbers greater than 10, use the formula: 2*funkcija(broj-2) - 3*funkcija(broj-4)
    else
    {
        memo.at(broj).izracunat = true;
        return memo.at(broj).vrednost = 2 * funkcija(broj-2, memo) - 3 * funkcija(broj-4, memo);
    }
}
