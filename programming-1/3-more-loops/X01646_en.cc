//SUM OF DIGITS (2)

//The program reads a basis for numeration and several numbers and prints the
//sum in base 10 of the digits in base b of each one.

//Input consists of the value of b≥ 2 followed by a sequence of natural
//numbers.
//Output: For every number, print the sum (in base 10) of its digits in base b
//following the format of the examples.

#include <iostream>

using namespace std;

int main() {
    int base; //base >= 2
    cin >> base;

    int num; //natural number

    while (cin >> num) {
        cout << num << ':' << ' ';

        int sum = 0;

        //Sums the digits
        while (num != 0) {
            sum += num % base;
            num /= base;
        }

        cout << sum << endl;
    }
}
