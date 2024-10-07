// MAXIMUM OF FOUR INTEGER NUMBERS

#include <iostream>

using namespace std;

// Returns the maximum number of two given integers.
int max2(int a, int b)
// Pre: true.
// Post: returns the maximum number of a, b.
{
    int res = a;
    if (b > a) res = b;

    return res;
}

// Returns the maximum number of four given integers.
int max4(int a, int b, int c, int d)
// Pre: true.
// Post: returns the maximum number of a, b, c, d.
{
    return max2(max2(a, b), max2(c, d));
}