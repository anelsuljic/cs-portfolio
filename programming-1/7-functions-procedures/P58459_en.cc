// VALID DATES


// Given a sequence of dates, the program tells if each one of them are valid
// dates or not.

// Input: a sequence of dates. Each dates is represented by three integers:
//        a day 'd', a month 'm', and a year 'y'. 1800 <= y <= 9999.
// Output: for each element of the sequence, prints "true" if it's a valid
//         date. Otherwise, prints "false".




#include <iostream>
using namespace std;



const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;



// Checks if a month is a one that has 31 days.
// Pre: ----
// Post: returns true if the 'm' is a month that has 31 days.
bool month_has_31_days(int m) {
    return (m == JAN or m == MAR or m == MAY or m == JUL or m == AUG 
            or m == OCT or m == DEC);
}



// Checks if a month is a one that has 30 days.
// Pre: ----
// Post: returns true if the 'm' is a month that has 30 days.
bool month_has_30_days(int m) {
    return (m == APR or m == JUN or m == SEP or m == NOV);
}



// Checks if a given year is a leap year or not (check the above the 
// description of a leap year).
// Pre: 1800 <= year <= 9999.
// Post: returns true if 'year' is a leap year. Otherwhise, returns 'false'.
bool is_leap_year(int year) {
    return (year % 100 == 0 and (year/100) % 4 == 0) or 
           (year % 100 != 0 and year % 4 == 0);
}



// Checks if a given date is valid or not.
// Pre: 1800 <= y <= 9999.
// Post: returns true if {d, m, y} is a valid date. Otherwise, returns false.
bool is_valid_date(int d, int m, int y) {
    bool res = false;
    if (month_has_31_days(m)) res = (d >= 1 and d <= 31);
    else if (month_has_30_days(m)) res = (d >= 1 and d <= 30);
    else if (m == FEB) {
        if (d == 29) res = is_leap_year(y);
        else res =  (d >= 1 and d <= 28);
    }

    return res;
}



/*
int main() {
    int d, m, y;    // 1800 <= y <= 9999
    while (cin >> d >> m >> y) {
        // Inv: it has been checked the validity of all treated dates.

        cout << (is_valid_date(d, m, y) ? "true":"false") << endl;
    }
}*/