//EASY OCTAGONS

//For every given n, the program prints an “octagon of size n” according to
//the pattern shown in the examples.

//Input consists in several natural numbers n ≥ 2.
//Output: For every n, print an “octagon of size n” using capital exes. Do not
//print any space to the right of the exes. Print an empty line after each
//octagon.

#include <iostream>

using namespace std;

int main() {
    int size; //natural numbers >= 2.

    while (cin >> size) {
        //Increasing part
        for (int i = 0; i < size - 1; ++i) {
            //Spaces
            for (int j = 0; j < size - 1 - i; ++j) {
                cout << ' ';
            }

            //X
            int sizeX = 2 * size + 2 * i - size;
            for (int k = 0; k < sizeX; ++k) {
                cout << 'X';
            }

            cout << endl;
        }

        //Body (constant part)
        for (int l = 0; l < size - 1; ++l) {
            //X
            int sizeX = 2 * size + size - 2;
            for (int m = 0; m < sizeX; ++m) {
                cout << 'X';
            }

            cout << endl;
        }

        //Decreasing part
        for (int n = size - 1; n >= 0; --n) {
            //Spaces
            for (int o = 0; o < size - 1 - n; ++o) {
                cout << ' ';
            }

            //X
            int sizeX = 2 * size + 2 * n - size;
            for (int p = 0; p < sizeX; ++p) {
                cout << 'X';
            }

            cout << endl;
        }

        cout << endl;
    }
}
