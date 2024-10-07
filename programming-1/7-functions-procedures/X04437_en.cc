// DISTANCE TO ORIGiN

#include <iostream>
#include <cmath>

using namespace std;

// Returns the distance to origin of a given point.
double dist_or(double x, double y)
// Pre: true.
// Post: returns the distance to origin of (x, y).
{
    return sqrt(x * x + y * y);
}