//LEAP YEARS

//The program tells if a year is a leap year or not. A leap year has 366 days.
//After the Gregorian reform, the leap years are those multiple of four that
//do not end with two zeros, and also the years ending with two zeros such
//that, after removing these two zeros, are divisible by four.

//Input consists of a natural number between 1800 and 9999.
//Output: If the year is a leap year, print “YES”; otherwise print “NO”.

#include <iostream>

using namespace std;

int main() {
    int year; //natural number between 1800 and 9999
    cin >> year;

    //Sees if a year is a leap year
    bool leap_year = false;
    //year is a leap year
    leap_year = (year % 100 != 0 and year % 4 == 0) or (year % 100 == 0 and
                (year / 100) % 4 == 0);

    if (leap_year) cout << "YES" << endl;
    else cout << "NO" << endl;
}
