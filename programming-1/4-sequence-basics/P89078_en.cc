//FIRST POSITION

//The program reads a sequence of natural numbers and prints the position of
//the first even number.

//Input consists of a sequence of natural numbers that contains, at least, one
//even number.
//Output: Print the position of the first even number of the sequence.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number

    int position = 0;
    bool found = false;

    while (not found and cin >> num) {
        ++position;
        found = num % 2 == 0;
    }

    cout << position << endl;
}
