//I-TH (3)

//Write a program that, given an integer number i and a sequence of natural //numbers x1, …, xn, prints xi.

//Input begins with an integer number i, followed by the sequence x1, …, xn.
//Output: If the position i is correct, print the content of i as it is shown //in the examples. Otherwise, print “Incorrect position.”.

#include <iostream>

using namespace std;

int main() {
	int position; //Integer number
	cin >> position;

	bool found = false;
	int num; //Natural number
	int counter = 1;

	//Looks for the number in the position given before.
	while (not found and cin >> num) {
		found = counter == position;

		++counter;
	}

	//Checks if there is a number in the given position.
	if (found) cout << "At the position " << position << " there is a(n) " << 			  num << '.' << endl;

	else cout << "Incorrect position." << endl;
}