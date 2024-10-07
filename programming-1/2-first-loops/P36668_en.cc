//SUM OF SQUARES

//The program reads a number n, and prints the sum of n squares.

//Input consists of a natural number n.
//Output: Print the sum of the first n squares.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    //Makes the sum of num squares.
    int result = 0;
    for (int i = 1; i <= num; ++i) {
        result += i * i;
    }

    cout << result << endl;
}
