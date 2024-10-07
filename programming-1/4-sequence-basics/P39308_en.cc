//DIVISORS IN ORDER

//Write a program to print in order all the divisors of a given number.

//Input consists of several cases, each with a natural number n between 1 and 
//109.
//Output: For every n, print the divisors of n in increasing order.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num; //natural number

    while (cin >> num) {
        cout << "divisors of " << num << ':';
	
	//Calculates small divisors
        for (int smalldiv = 1; smalldiv <= sqrt(num); ++smalldiv) {
	    if (num % smalldiv == 0) cout << ' ' << smalldiv;
	}

	//Calculates large divisors
	for (int lardiv = sqrt(num); lardiv > 0; --lardiv) {
	    if (num % lardiv == 0 and lardiv != num / lardiv) {
		cout << ' ' << num / lardiv;
	    }
	}

	cout << endl;
    }
}