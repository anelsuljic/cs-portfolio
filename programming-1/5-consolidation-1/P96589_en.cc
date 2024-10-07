// CONTROL C101C

// The program reads an ASCII character and prints to the std output channel 
// whether it's a letter, a digit, or any of them.

// Input: an ASCII character.
// Output: a line with one of the following strings: "lletra" for letters,
//         "digit" for digits, "res" for nothing.

// Examples of input and output:
//
// Inp: C               Inp: 7              Inp: $
// Out: lletra          Out: digit          Out: res


#include <iostream>
using namespace std;


int main()
{
    char c;
    cin >> c;

    // A letter.
    if (('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z')) {
        cout << "lletra" << endl;
    }
    // A digit.
    else if ('0' <= c and c <= '9') cout << "digit" << endl;
    // Nothing.
    else cout << "res" << endl;
}