// FUNCTION FOR THE SUM OF THE MINIMUM AND THE MAXIMUM OF THREE INTEGERS

#include <iostream>

using namespace std;

// Returns the minimum of two integers.
int min(int x, int y)
// Pre: true.
// Post: returns the minimum of x and y.
{
    int res = x;
    if (y < x) res = y;
    
    return res;
}

// Returns the maximum of two integers.
int max(int x, int y)
// Pre: true.
// Post: returns the maximum of x and y.
{
    int res = x;
    if (y > x) res = y;

    return res;
}

// Returns the sum of the maximim and the minimum of three integers.
int sum_min_max(int x, int y, int z)
// Pre: 0 < x, y, z < 10⁹.
// Post: returns the sum of the maximum and the minimum of x, y, z.
{
    return min(min(x, y), z) + max(max(x, y), z);
}