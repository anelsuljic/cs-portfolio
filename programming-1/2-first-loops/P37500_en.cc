//FIRST NUMBERS

//The program reads a number n, and prints all numbers between 0 and n.

//Input consists of a natural number n.
//Output: Print in order all natural numbers between 0 and n.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    //Prints all the numbers between 0 and num.
    for (int i = 0; i <= num; ++i) {
        cout << i << endl;
    }
}
