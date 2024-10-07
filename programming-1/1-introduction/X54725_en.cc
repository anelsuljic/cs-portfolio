//MINIMUM OF TWO INTEGERS

//The program reads two numbers and prints their minimum.

//Input consists of two integer numbers.
//Output: print a line with the minimum of the two numbers.

#include <iostream>

using namespace std;

int main() {
    int firstnum, secondnum; //integer numbers
    cin >> firstnum >> secondnum;

    int min = 0;
    //firstnum < secondnum
    if (firstnum < secondnum) min = firstnum;

    //secondnum < firstnum
    else min = secondnum;

    cout << min << endl;
}
