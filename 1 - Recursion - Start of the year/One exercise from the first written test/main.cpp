#include <iostream>

using namespace std;

// Recursive function to compute a value based on the input number `n`
// @param n: the input number used to determine the output value
// @return: computed value based on the conditions
unsigned long long int fun(unsigned long long int n){
    if (n <= 2) {
        return 3; // Base case: return 3 if n is 2 or less
    } else if (n > 2 && n < 10) {
        return 2 * fun(n - 1); // Recursive case: double the result of fun(n-1) if n is between 3 and 9
    } else if (n >= 10) {
        return fun(n - 1) + 3 * fun(n - 2); // Recursive case: sum of fun(n-1) and three times fun(n-2) if n is 10 or more
    }
}

int main()
{
    unsigned long long int a;
    cin >> a; // Input the number `a` from the user
    cout << fun(a); // Call the function and print the result
    return 0;
}
