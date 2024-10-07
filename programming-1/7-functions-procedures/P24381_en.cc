//PRINT A CROSS

//Write a procedure "void cross(int n, char c);" to print an n × n cross with
//the character c.
//Input is an odd number n >= 3, and a character c.
//Output: prints the cross n * n with the character c.

#include <iostream>

using namespace std;

//Prints a cross n * n.
//Pre: n >= 3 and a character c.
//Post: a cross.
void cross(int n, char c) {
    //Prints the first half of the vertical part
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            cout << ' ';
        }
        cout << c << endl;
    }
    //Prints the horizontal part
    for (int k = 0; k < n; ++k) {
        cout << c;
    }
    cout << endl;
    //Prints the second half of the vertical part
    for (int l = 0; l < n / 2; ++l) {
        for (int m = 0; m < n / 2; ++m) {
            cout << ' ';
        }
        cout << c << endl;
    }
}

int main() {
    int num;
    char character;

    while (cin >> num >> character) cross(num, character);
}
