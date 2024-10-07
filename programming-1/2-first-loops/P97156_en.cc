//NUMBERS IN AN INTERVAL

//The program reads two numbers a and b, and prints all numbers between a and
//b.

//Input consists of two natural numbers a and b.
//Print a line with a,a+1,…,b−1,b. Separate the numbers with commas.

#include <iostream>

using namespace std;

int main() {
    int first, second; //natural numbers
    cin >> first >> second;

    //Prints the numbers between first and second
    if (first > second) cout << endl;

    else {
        while (first < second) {
            cout << first << ',';
            ++first;
        }
        cout << second << endl;
    }
}
