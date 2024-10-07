// HARMONIC NUMBERS (1)


#include <iostream>
using namespace std;


// Reads a natural number, n, and prints the n-th harmonic number with
// four digits of precision.
// Pre: n >= 0.
// Post: H(n) = 1 + 1/2 + 1/3 + ... + 1/n.
int main()
{
    unsigned int num;
    cin >> num;

    double harm_num = 0;
    for (unsigned int i = 1; i <= num; ++i) harm_num += 1/double(i);

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << harm_num << endl;
}