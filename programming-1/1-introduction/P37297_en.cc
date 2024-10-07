//CONTROL C101A

//The program reads a natural number and prints the sum of their three
//last digits.
//The input is a natural number n ≥ 100.
//The output is a line with the sum of the last three digits of n.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number >= 100.
    cin >> num;
    
    //Selects the three last digits of num and makes their sum.
    int sum = num % 10 + (num / 10) % 10 + (num/100) % 10;
    
    cout << sum << endl;
}
