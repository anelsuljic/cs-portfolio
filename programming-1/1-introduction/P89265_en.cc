//INTERVALS (3)

//Given two intervals, the program tells if one is inside the other, and
//computes the interval corresponding to their intersection, or tells that it
//is empty.

//Input consists of four integer numbers a1, b1, a2, b2 that represent the
//intervals [a1,b1] and [a2,b2]. Assume a1≤ b1 and a2≤ b2.
//Output: Print ‘=’ if the intervals are equal, ‘1’ if the first is inside the
//second (but they are not equal), ‘2’ if the second is inside the first (but
//they are not equal), or ‘?’ otherwise. Also, print “[]” if the intersection
//is empty, or “[x,y]” if this is their non-empty intersection.

#include <iostream>

using namespace std;

int main() {
    int firstelem, secondelem, thirdelem, fourthelem; //integer numbers
    cin >> firstelem >> secondelem >> thirdelem >> fourthelem;

    //They are equal.
    if (firstelem - thirdelem == 0 and secondelem - fourthelem == 0) {
        cout << '=' << ' ' << ',' << ' ' << '[' << firstelem << ',' <<
             secondelem << ']' << endl;
    }

    //The first is inside the second
    else if (thirdelem <= firstelem and fourthelem >= secondelem) {
        cout << '1' << ' ' << ',' << ' ' << '[' << firstelem << ',' <<
             secondelem << ']' << endl;
    }

    //The second is inside the first
    else if (thirdelem >= firstelem and fourthelem <= secondelem) {
        cout << '2' << ' ' << ',' << ' ' << '[' << thirdelem << ',' <<
             fourthelem << ']' << endl;
    }

    //There's no intersection
    else if (secondelem < thirdelem or fourthelem < firstelem) {
        cout << '?' << ' ' << ',' << ' ' << '[' << ']' << endl;
    }

    //[thirdelem, fourthelem]
    else if (thirdelem >= firstelem and fourthelem <= secondelem) {
        cout << '?' << ' ' << ',' << ' ' << '[' << thirdelem << ',' <<
             fourthelem << ']' << endl;
    }

    //[thirdelem, secondelem]
    else if (thirdelem >= firstelem and fourthelem > secondelem) {
        cout << '?' << ' ' << ',' << ' ' << '[' << thirdelem << ',' <<
             secondelem << ']' << endl;
    }

    //[firstelem, fourthelem]
    else if (thirdelem < firstelem and fourthelem <= secondelem) {
        cout << '?' << ' ' << ',' << ' ' << '[' << firstelem << ',' <<
             fourthelem << ']' << endl;
    }

    //[firstelem, secondelem]
    else cout << '?' << ' ' << ',' << ' ' << '[' << firstelem << ',' <<
              secondelem << ']' << endl;
}
