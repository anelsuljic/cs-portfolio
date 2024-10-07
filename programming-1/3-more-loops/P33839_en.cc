//SUM OF DIGITS

//The program reads several numbers and prints the sum of the digits of each
//one.

//Input consists of a sequence of natural numbers.
//Output: For every number, print the sum of its digits following the format
//of the example.

#include <iostream>

using namespace std;

int main() {
    int num; //natural numbers

    while (cin >> num) {
        cout << "The sum of the digits of " << num << " is ";

        int sum = 0;

        //Sums the digits
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }

        cout << sum << '.' << endl;
    }
}
