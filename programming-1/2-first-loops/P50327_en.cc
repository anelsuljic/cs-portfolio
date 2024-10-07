//REVERSED NUMBER

//The program reads a number and prints it reversed.

//Input consists of a natural number.
//Output: Print the number reversed, with as many zeros at its left as it has 
//at its right.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;
    
    //Prints the first digit of reversed num
    cout << num % 10;
    num /= 10;
    
    //Reverses the rest of digits of num
    while (num != 0) {
        cout << num % 10;
        num /= 10;
    }
    cout << endl;
}
