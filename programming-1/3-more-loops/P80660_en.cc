//THE SEQUENCE OF COLLATZ

//The program calculates the sequence of Collatz. If n is an even number, we 
//divide it by two. Otherwise, we multiply it by 3 and add 1 to it. When we 
//reach 1, we stop.

//Input consists of several natural numbers n ≥ 1.
//Output: For every n, print how many steps are needed to reach 1. Suppose 
//that this number is well defined, that is, that the conjecture of the 
//statement is true.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number > 0
   
    while (cin >> num) {
        int counter = 0;
        
        //Calculates the sequence of Collatz
        while (num != 1) {
            ++counter;
            
            if (num % 2 == 0) num /= 2;
            else num = 3 * num + 1;
        }
        
        cout << counter << endl;
    }
}
