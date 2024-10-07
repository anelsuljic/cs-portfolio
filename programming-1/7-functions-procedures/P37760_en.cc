// TRIGONOMETRY

#include <iostream>
#include <cmath>

using namespace std;

// Returns the sine of an angle in degrees.
double sine(double angle)
// Pre: true.
// Post: returns the sine of "angle".
{
    return sin(angle * M_PI / 180);
}

// Returns the cosine of an angle in degrees.
double cosine(double angle)
// Pre: true.
// Post: returns the sine of "angle".
{
    return cos(angle * M_PI / 180);
}

// Reads a sequence of angles in degrees (real numbers) and, for every of them,
// prints their sine and cosine with six decimal digits of precision.
int main()
// Input: a sequence of real numbers that represent angles in degrees.
// Output: for each angle, prints its sine and cosine with six decimal digits 
// of precision.
{
    double angle;
    cout.setf(ios::fixed);
    cout.precision(6);
    while (cin >> angle) cout << sine(angle) << ' ' << cosine(angle) << endl;
}