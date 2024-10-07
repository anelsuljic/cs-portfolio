//CONTROL C201A

//The program prints if a given number is cool or is not. A number is cool if
//the sum of its digits in odd positions is an even number.

//The input is a natural number n.
//Output: print in a line if n is cool or is not.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    cout << num << ' ';

    int result = 0;

    while (num != 0) {
        result += num % 10;
        num /= 100;
    }

    //Sees if it's cool or not
    bool cool = result % 2 == 0;

    if (cool) cout << "IS COOL" << endl;
    else cout << "IS NOT COOL" << endl;
}
