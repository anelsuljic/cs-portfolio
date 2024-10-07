//MAXIMUM OF TREE INTEGER NUMBERS

//The program reads three numbers and prints their maximum.

//Input consists of three integer numbers.
//Print a line with the maximum of the three numbers.

#include <iostream>

using namespace std;

int main() {
    int firstnum, secondnum, thirdnum; //integer numbers
    cin >> firstnum >> secondnum >> thirdnum;

    int max = 0;
    //firstnum > secondnum
    if (firstnum >= secondnum) max = firstnum;

    //secondnum > firstnum
    else if (secondnum >= firstnum) max = secondnum;

    //thirdnum is the max
    if (thirdnum > max) max = thirdnum;

    cout << max << endl;
}
