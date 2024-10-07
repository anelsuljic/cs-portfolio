//NUMBER OF DIGITS (1)

//The program reads a number and prints its number of digits.

//Input consists of a natural number n.
//Output: print the number of digits of n.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    cout << "The number of digits of" << ' ' << num << ' ' << "is" << ' ';

    //Counts its digits
    int counter = 0;
    if (num == 0) counter = 1;

    while (num > 0) {
        ++counter;
        num /= 10;
    }

    cout << counter << '.' << endl;
}
