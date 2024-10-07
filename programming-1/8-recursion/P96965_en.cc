//REDUCTION OF DIGITS

//Write a function that, given a natural number x, returns the reduction of
//its digits. We say that reducing the digits of a number means computing the
//sum of its digits.

//Input is a natural number.
//Output: prints the reduction of digits of that number.

#include <iostream>

using namespace std;

//Sums the digits of a natural number.
//Pre: a natural number.
//Post: returns sum.
int sum_of_digits(int num) {
    int sum = 0;

    //Basic case
    if (num < 10) sum = num;

    //Recursive case
    else sum = num % 10 + sum_of_digits(num / 10);

    return sum;
}

//Makes the reduction of digits of one number.
//Pre: x is a natural number.
//Post: returns result.
int reduction_of_digits(int x) {
    int result = 0;
    //Recursive condition
    if (x > 9) {
        result = reduction_of_digits(sum_of_digits(x));
    }

    //Basic case
    else result = x;

    return result;
}

int main() {
    int num;

    while (cin >> num) {
        cout << reduction_of_digits(num) << endl;
    }
}
