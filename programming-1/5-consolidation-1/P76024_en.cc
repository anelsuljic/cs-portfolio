// SUM OF FRACTIONS

// The program reads a sequence whose elements are triples of natural numbers
// (call them a, b, k), and for each one, computes and prints the result of
// 1/a + 1/(a + k) + 1/(a + 2*k) + ... for all fractions with denominator
// smaller or equal than b.

// Input: a sequence of triples of natural numbers (a, b, k) such that 
//        1 <= a <= b and k >= 1.
// Output: for every element of the sequence read, prints a line with the
//         result of the operation (see program description) with four digits
//         after the decimal point.

// Example of input and output (only one element of the sequence):
//
// Inp: 1 3 1
// Out: 1.8333


#include <iostream>
using namespace std;


int main()
{
    int a, b, k;    // natural numbers such that 1 <= a <= b and k >= 1.
    while (cin >> a >> b >> k) {
        // Inv 1: the std output channel contains all the results printed with
        //        four digits after the decimal point of all treated triples.

        int i = 0;
        int den = a + i*k;
        double res = 0;
        while (den <= b) {
            // Inv 2: res = 1/a + ... + 1/(a + (i-1)*k); i >= 0; den = a + i*k.

            res += 1/double(den);
            ++i;
            den = a + i*k;
        }

        cout.setf(ios::fixed);
        cout.precision(4);

        cout << res << endl;
    }
}