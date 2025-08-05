
#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

// iterative way for gcd

int gcd_iterative(int a, int b)
{

    int temp = 0;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Driver program to test above function
int main()
{
    int a = 8, b = 24;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    cout << "\nGCD of " << a << " and " << b << " is " << gcd_iterative(a, b);

    return 0;
}