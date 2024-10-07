// POLYNOMIAL EVALUATION (1)


// The program reads a number 'x' and a polynomial p(z) = c_0*z^0 + .. + 
// + c_n*z^n, and prints the result of p(x).

// Input: the standard input channel contains a real number 'x' followed by the
//        description of p(z): the real coefficients c_0, c_1, ... , c_n
//        separated by a space, in this order.
// Output: the standard output channel contains the result of p(x) with four
//         digits after the decimal point.

// Example of input/output:
//
// Inp: 2
//      3 4 5
// Out: 31.0000
//
// Note: the above input represents p(z) = 3 + 4*z + 5*z^2 at x = 2.


#include <iostream>
using namespace std;


int main()
{
    double x;
    cin >> x;

    double coef;
    double factor = 1;
    double p_x = 0;
    while (cin >> coef) {
        // Inv: p_x = coef(0)*factor(0) + ... + coef(j)*factor(j); 
        //      factor = x^j; j = "number of coeficients already read from the 
        //      std input channel" - 1.

        p_x += coef*factor;
        factor *= x;
    }

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << p_x << endl;
}