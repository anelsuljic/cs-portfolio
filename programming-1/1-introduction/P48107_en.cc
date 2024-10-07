//INTEGER DIVISION AND REMINDER OF TWO NATURAL NUMBERS

//The program reads two natural numbers a and b, with b > 0, and prints the 
//integer division d and the remainder r of a divided by b.
//Input consists of a and b, with b > 0.
//Output: Print a line with the integer division and the remainder of a 
//divided by b, separated by a space.

#include <iostream>

using namespace std;

int main() {
    int numerator, divisor; //natural numbers and divisor > 0.
    cin >> numerator >> divisor;
    
    //Opearates the quotient and the reminder.
    int quotient = numerator / divisor;
    int reminder = numerator % divisor;
    
    cout << quotient << ' ' << reminder << endl;
}
