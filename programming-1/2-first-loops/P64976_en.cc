//CONTROL C201B

//The program reads a natural number n and prints the n first lines of its
//multiplication table.

//The input is a natural number n.
//Output: print the n first lines of the multiplication table of n.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    //Prints the multiplication table
    for (int i = 1; i <= num; ++i) {
        int result = num * i;

        cout << num << ' ' << 'x' << ' '<< i << ' ' << '=' << ' ' << result
             << endl;
    }
}
