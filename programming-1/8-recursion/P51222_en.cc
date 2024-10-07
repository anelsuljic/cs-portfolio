//RECURSIVE NUMBER OF DIGITS

//Write a recursive function that returns the number of digits of n.

//Input: a natural number.
//Output: prints the number of digits of the number.

#include <iostream>

using namespace std;

int number_of_digits(int n) {
    int result = 0;

    //Base case
    if (n < 10) result = 1;

    //Recursive condition
    else result = 1 + number_of_digits(n / 10);

    return result;
}

int main() {
    int num;

    while (cin >> num) {
        cout << number_of_digits(num) << endl;
    }
}
