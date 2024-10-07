// RECURSIVE GREATEST COMMON DIVISOR

#include <iostream>

using namespace std;

// Computes the gratest common divisor using the Euclidean algorithm.
int gcd(int a, int b)
// Pre: a,b >= 0; one of them is strictly greater than zero.
// Post: returns the gratest common divisor of a and b.
{
    int res;
    if (b == 0) res = a;
    else res = gcd(b, a % b);

    return res;
}