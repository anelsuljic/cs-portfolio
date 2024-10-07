// APPROXIMATION OF e

#include <iostream>

using namespace std;

// Computes an approximation of number e using the Taylor series.
int main()
// Input: several natural numbers in the interval [0, 20].
// Output: for every given n, prints with 10 digits after the decimal point the 
// approximation of e that we get by adding the n first terms of the series 
// above.
{
    unsigned int num;
    while (cin >> num) {
        double approx_e = 0;
        double terme = 0;
        for (unsigned int i = 0; i < num; ++i) {
            if (i == 0) terme = 1;
            else terme *= 1 / double(i);
            approx_e += terme;
        }

        cout.setf(ios::fixed);
        cout.precision(10);
        cout << "With " << num << " term(s) we get " << approx_e << '.' << endl;
    }
}