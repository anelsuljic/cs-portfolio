//PRODUCT OF DIGITS

//The program reads several numbers, and for each one prints the product of
//its digits, and the product of the digits of the latest product, etcetera,
//until the resulting product has just one digit.

//Input consists of several natural numbers.
//Output: For every number, print the product of the digits of the number, the
//product of the digits of the previous product, etcetera, one per line,
//until the resulting product has just one digit. Print a line with 10 dashes
//after the output for every number.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number

    while (cin >> num) {
        //The product of the digit of number with one digit is itself.
        if (num < 10) {
            cout << "The product of the digits of " << num << " is " << num
                 << '.' << endl;
        }

        //Makes all the products until the resulting product has one digit.
        while (num >= 10) {
            cout << "The product of the digits of " << num << " is ";

            int result = 1;

            //Computes the product of the number
            while (num != 0) {
                result *= num % 10;

                num /= 10;
            }

            cout << result << '.' << endl;

            num = result;
        }

        cout << "----------" << endl;
    }
}
