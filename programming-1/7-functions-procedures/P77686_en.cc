//PALINDROMIC NUMBERS

//Write a function that tells whether the natural number n is a palindromic 
//number or not.

//Input: a natural number.
//Output: prints true or false whether the number is palindromic or not.

#include <iostream>

using namespace std;

//Reverses a number
//Pre: a natural number
//Post: returns the number reversed
int reversed_num(int num) {
    int reversed = 0;
    
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    return reversed;
}

//Sees if a number is palindromic or not
//Pre: a natural number.
//Post: returns true if the number is palindromic
bool is_palindromic(int n) {
    int reversed = reversed_num(n);
    
    return n == reversed;
}

int main() {
    int num;
    
    while (cin >> num) {
        if (is_palindromic(num)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}
