//POWERS

//The program computes powers.

//Input consists of several pairs of integer numbers a and b. Assume b ≥ 0.
//Output: For every pair a,b, print a exp b. Supose, as usual, that 0 exp 0 =
//1.

#include <iostream>

using namespace std;

int main() {
    int num, exp; //num = integer number; exp = natural number.

    //Reads every element
    while (cin >> num >> exp) {
        int result = 1;

        //Calculates every power
        for (int i = 0; i < exp; ++i) {
            result *= num;
        }

        cout << result << endl;
    }
}
