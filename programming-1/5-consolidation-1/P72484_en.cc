// RHOMBUS

#include <iostream>

using namespace std;

// Given a natural number, n, prints a rhombus of size n.
int main()
// Input: a natural number, n >= 1.
// Output: a rhombus of size n. Prints 2*n - 1 lines.
{
    unsigned int num;
    cin >> num;

    // Triangle
    for (unsigned int i = 1; i <= num; ++i) {
        for (unsigned int j = 0; j < num - i; ++j) cout << ' ';
        for (unsigned int k = 1; k < 2 * i; ++k) cout << '*';
        cout << endl;
    }
    // Reversed triangle
    for (unsigned int l = num - 1; l > 0; --l) {
        for (unsigned int m = 0; m < num - l; ++m) cout << ' ';
        for (unsigned int n = 1; n < 2 * l; ++n) cout << '*';
        cout << endl;
    }
}