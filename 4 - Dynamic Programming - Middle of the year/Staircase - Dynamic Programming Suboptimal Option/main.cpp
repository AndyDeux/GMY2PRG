#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n; // Input the index for which the sequence value is required
    int niz[n+1]; // Array to store the sequence values

    // Initial values for the sequence
    niz[0] = 0;
    niz[1] = 1;
    niz[2] = 2;
    niz[3] = 4;

    // Compute the sequence values from the 4th element onward
    for(int i = 4; i < n+1; ++i)
    {
        niz[i] = niz[i-1] + niz[i-2] + niz[i-3]; // Sum of the previous three terms
    }

    cout << niz[n]; // Output the value of the sequence at index n
}
