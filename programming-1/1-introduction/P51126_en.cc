//INTERVALS (1)

//Given two intervals, the program computes the interval corresponding to
//their intersection, or tells that it is empty.

//Input consists of four integer numbers a1, b1, a2, b2 that represent the
//intervals [a1,b1] and [a2,b2]. Assume a1≤ b1 and a2≤ b2.
//Output: Print “[]” if their intersection is empty, or “[x,y]” if this is
//their non-empty intersection.

#include <iostream>

using namespace std;

int main() {
    int firstelem, secondelem, thirdelem, fourthelem; //integer numbers
    cin >> firstelem >> secondelem >> thirdelem >> fourthelem;
    
    //Selects which could be the first number of the intersection.
    int maxfirstthird = firstelem;
    if (thirdelem > firstelem) maxfirstthird = thirdelem;
    
    //Selects which could be the second number of the intersection.
    int minsecondfourth = secondelem;
    if (fourthelem < secondelem) minsecondfourth = fourthelem;
    
    //Sees if finally there is an intersection
    if (minsecondfourth >= maxfirstthird) {
        cout << '[' << maxfirstthird << ',' << minsecondfourth << ']' << endl;
    }
    else cout << '[' << ']' << endl;
}
