// REVERSED NUMBER IN BINARY


#include <iostream>
using namespace std;


// Reads a natural number and prints, reversed, its binary representation.
int main()
{
    unsigned int num;
    cin >> num;

    if (num == 0) cout << num;
    while (num != 0) {
        cout << (num & 1);
        num >>= 1;
    }
    cout << endl;
}