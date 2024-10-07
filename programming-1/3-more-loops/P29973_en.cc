//TRIANGLE

//The program, given a number n, prints a “triangle of size n”.

//Input consists of a natural number n.
//Output: Print n lines, in such a way that the i-th line contains i
//asterisks.

#include <iostream>

using namespace std;

int main() {
    int size; //natural number
    cin >> size;

    //Prints every line
    for (int i = 0; i < size; ++i) {
        //Prints every column
        for (int j = 0; j <= i; ++j) {
            cout << '*';
        }
        cout << endl;
    }
}
