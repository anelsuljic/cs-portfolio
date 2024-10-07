//BARS(1)

//The program reads a natural number n, and prints 2expN − 1 bars of asterisks

//Input consists of a natural number n > 0.
//Output: Print 2expN − 1 lines.

#include <iostream>

using namespace std;

//Given a number n, prints a line of n asterisks.
//Pre: a natural number.
//Post: ----------
void asterisk_line(int num) {
    //While num > 0, executes the recursive procedure.
    if (num > 0) {
        asterisk_line(num - 1);
        
        cout << '*';
    }
}

//Prints 2^n - 1 bars of asterisks
//Pre: a natural number.
//Post: ----------
void bars(int num) {
    //Basic condition
    if (num == 1) cout << '*' << endl;
    //Recursive condition
    else {
        bars(num - 1);
        //Line of num asterisks
        asterisk_line(num);
        cout << endl;
        
        bars(num - 1);
    }
}

int main() {
    int num; //natural number
    
    while (cin >> num) {
        bars(num);
    }
}
