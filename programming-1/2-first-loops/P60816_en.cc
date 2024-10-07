//REVERSED NUMBER IN HEXADECIMAL

//The program reads a number and prints its hexadecimal representation
//reversed.

//Input consists of a natural number.
//Output: Print, reversed, the hexadecimal representation of the number, with
//as many zeros at its left as required.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    //Convertion to hexadecimal
    if (num == 0) cout << 0;
    while (num > 0) {
        int hexdigit = num % 16;

        //Sees when if is necessary to use characters
        if (hexdigit > 9) cout << char('A' + hexdigit - 10);
        else cout << hexdigit;

        num /= 16;
    }

    cout << endl;
}
