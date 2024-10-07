// FUNCTION FOR LEAP YEARS


// Given a sequence of years represented as natural numbers between 1800 and
// 9999 (both included), the program checks and prints for each element of 
// the sequence if it's a leap year or not. A leap year is the one that
// accomplishes one of the following two conditions: 1) it doesn't end with
// two zeros and is divisible by four; 2) it ends with two zeros and, after
// removing them, the remaining number is divisible by four.

// Input: a sequence of natural numbers between 1800 and 9999, both included.
// Output: for each element of the sequence, prints "true" if it's a leap year.
//         Otherwise, prints "false".

// Example of input/output (only for one element of the sequence):
//
// Inp: 1968        Inp: 2400
// Out: true        Out: true


#include <iostream>
using namespace std;


// Checks if a given year is a leap year or not (check the above the 
// description of a leap year).
// Pre: 1800 <= year <= 9999.
// Post: returns true if 'year' is a leap year. Otherwhise, returns 'false'.
bool is_leap_year(int year) {
    return (year % 100 == 0 and (year/100) % 4 == 0) or 
           (year % 100 != 0 and year % 4 == 0);
}

/*
int main() {
    int year;      // 1800 <= year <= 9999
    while (cin >> year) cout << (is_leap_year(year) ? "true":"false") << endl;
}
*/