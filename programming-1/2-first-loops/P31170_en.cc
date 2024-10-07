//MULTIPLICATION TABLE

//The program reads a number n and prints the “multiplication table” of n.

//Input consists of a natural number n between 1 and 9.
//Output: Print the “multiplication table” of n.

#include <iostream>

using namespace std;

const int TEN = 10;

int main() {
    int num; //natural number between 1 and 9
    cin >> num;

    //Makes the multiplication table
    for (int i = 1; i <= TEN; ++i) {
        int result = num * i;

        cout << num << '*' << i << ' ' << '=' << ' ' << result << endl;
    }
}
