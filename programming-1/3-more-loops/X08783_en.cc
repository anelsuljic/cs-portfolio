//HOW MANY DIGITS?

//The program computes the number of digits in several bases.

//Input consists of a sequence of pairs of natural numbers b and n, such that 
//b≥ 2 and n≥ 1.
//Output: For every pair, print the number of digits of n in base b.

#include <iostream>

using namespace std;

int main() {
    int base, num; //base >= 2; num >= 1
   
    while (cin >> base >> num) {
        int digits = 0;
        
        //Counts the digits
        while (num != 0) {
            ++digits;
            num /= base;
        }
        
        cout << digits << endl;
    }
}
