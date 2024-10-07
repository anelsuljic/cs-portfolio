//BARS (3)

//The program reads a natural number n, and prints 2^n − 1 bars of asterisks,
//following the pattern that can be deduced from the examples.

//Input consists of a natural number n > 0.
//Output: Print 2^n − 1 lines, following the pattern that can be deduced from
//the examples.

#include <iostream>

using namespace std;

//Prints a line of asterisks
//Pre: a natural number.
//Post: --------------
void asterisk_line(int num) {
    //The recursive condition finishes when num == 0
    if (num > 0) {
        asterisk_line(num - 1);
        cout << '*';
    }
}

//Prints 2^n - 1 lines of asterisks
//Pre: a natural number.
//Post: --------------
void bars(int num) {
    if (num == 1) cout << '*' << endl;
    else {
        bars(num - 1);
        bars(num - 1);
        asterisk_line(num);
        cout << endl;
    }
}

int main() {
    int num;

    while (cin >> num) {
        bars(num);
    }
}
