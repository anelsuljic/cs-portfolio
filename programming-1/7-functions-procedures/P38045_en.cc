// COMPUTING SQUARE ROOTS AND SQUARES

#include <iostream>
#include <cmath>

using namespace std;

// Computes the square of a natural number.
int square(unsigned int num)
// Pre: true.
// Post: returns the square of num.
{
    return num * num;
}

// Computes the square root of a natural number.
double root(unsigned int num)
// Pre: true.
// Post: return the square root of num.
{
    return sqrt(double(num));
}

// Reads a sequence of natural numbers and prints the square and the square
// root of each one.
int main()
// Input: a sequence of natural numbers.
// Output: for every number, prints its square and its square root with six 
// decimal digits of precision.
{
    unsigned int num;
    cout.setf(ios::fixed);
    cout.precision(6);
    while (cin >> num) cout << square(num) << ' ' << root(num) << endl;
}