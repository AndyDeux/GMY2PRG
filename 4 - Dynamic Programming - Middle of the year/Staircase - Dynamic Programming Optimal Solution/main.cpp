#include <iostream>

using namespace std;

struct podatak
{
    bool izracunat; // Indicates if the value has been computed
    int vrednost;   // Stores the computed value
};

int fun(int, podatak[]);

int main(void)
{
    int n;
    cin >> n; // Input the index for which the sequence value is required
    podatak niz[n+1]; // Array to store computed values and their status
    podatak x = {false, 0}; // Initialize struct with default values

    // Initialize all elements of the array
    for (int i = 0; i < n+1; i++)
    {
        niz[i] = x;
    }

    cout << fun(n, niz); // Compute and output the result for index n

    return 0;
}

int fun(int n, podatak niz[])
{
    // Return the stored value if already computed
    if (niz[n].izracunat)
        return niz[n].vrednost;

    // Compute base cases
    else if (n == 0)
    {
        niz[n].izracunat = true;
        return niz[n].vrednost = 0;
    }
    else if (n == 1)
    {
        niz[n].izracunat = true;
        return niz[n].vrednost = 1;
    }
    else if (n == 2)
    {
        niz[n].izracunat = true;
        return niz[n].vrednost = 2;
    }
    else if (n == 3)
    {
        niz[n].izracunat = true;
        return niz[n].vrednost = 4;
    }
    else
    {
        // Compute value for n based on previous values
        niz[n].vrednost = fun(n-1, niz) + fun(n-2, niz) + fun(n-3, niz);
        niz[n].izracunat = true;
        return niz[n].vrednost;
    }
}
