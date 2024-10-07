//CHANGES OF BASE

//Use recursion in order to write a program that prints every given number in 
//binary, octal and hexadecimal notation.

//Input consists of several natural numbers.
//Output: For every given number, print its binary, octal and hexadecimal 
//notation.

#include <iostream>

using namespace std;

//Changes the base of a natural number.
//Pre: a natural number and the base.
//Post: returns the number in another base.
void change_of_base(int num, int base) {
    if (num > 0) {
        //Recursive function
        change_of_base(num / base, base);
        
        //Base conditions
        int result = num % base;
        
        //For hexadecimals
        if (result > 9) {
            cout << char('A' + result - 10);
        }
        
        else cout << result;
    }
}

int main() {
    int num;
    
    while (cin >> num) {
        //Prints every convertion
        cout << num << ' ' << '=' << ' ';
        
        if (num == 0) cout << "0, 0, 0" << endl;
        else {
            change_of_base(num, 2);
        
            cout << ',' << ' ';
        
            change_of_base(num, 8);
        
            cout << ',' << ' ';
        
            change_of_base(num, 16);
        
            cout << endl;
        }
    }
}
