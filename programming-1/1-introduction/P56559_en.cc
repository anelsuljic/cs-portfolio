//INTERVALS (2)

//Given two intervals, the program tells if one is inside the other.

//Input consists of four integer numbers a1, b1, a2, b2 that represent the
//intervals [a1,b1] and [a2,b2]. Assume a1≤ b1 and a2≤ b2.
//Output: Print ‘=’ if the intervals are equal, ‘1’ if the first is inside the
//second (but they are not equal), ‘2’ if the second is inside the first (but
//they are not equal), or ‘?’ otherwise.

#include <iostream>

using namespace std;

int main() {
    int firstelem, secondelem, thirdelem, fourthelem; //integer numbers
    cin >> firstelem >> secondelem >> thirdelem >> fourthelem;

    //Sees if they are equal.
    if (firstelem - thirdelem == 0 and secondelem - fourthelem == 0) {
        cout << '=' << endl;
    }

    //The first is inside the second
    else if (thirdelem <= firstelem and fourthelem >= secondelem) {
        cout << '1' << endl;
    }

    //The second is inside the first
    else if (thirdelem >= firstelem and fourthelem <= secondelem) {
        cout << '2' << endl;
    }

    //No one is inside the other one
    else cout << '?' << endl;
}
