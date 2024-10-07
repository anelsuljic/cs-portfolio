// INTEREST (1)


#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// Reads a positive natural number that representa an initial capital and
// prints the final capital that is obtained by applying a simple or a
// compound interest rate to the initial capital.
int main()
{
    double capital, int_rate;   // capital, int_rate > 0
    unsigned int years;         // years > 0
    string type;                // type == {"simple", "compound"}
    cin >> capital >> int_rate >> years >> type; 

    double increment;
    if (type == "simple") increment = 1 + int_rate/100*years;
    else increment = pow(1 + int_rate/100, years);

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << capital * increment << endl;
}