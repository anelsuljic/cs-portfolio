//ALLOWANCE (2)

//Write a program that counts how many weeks you end up with a strictly //positive balance.
//The input consists of three naturals d ? 0, n ? 0 and t> 0. Following, //there are the quantities corresponding to the t weekly allowances a1, //..., at 
//Output: The output is a natural number indicating the number of weeks //which end up with a strictly positive balance, after paying the weekly //expenses

#include <iostream>

using namespace std;

int main() {
	int weekexp, savings, weeks; //natural numbers
	cin >> weekexp >> savings >> weeks;

	int earnings = 0; 
	int numweeks = 0; //counter of weeks with positive balance
	
	//Sees how many weeks have a positive balance
	for (int i = 0; i < weeks; ++i) {
		int allowance; //natural number
		cin >> allowance;

		earnings += allowance - weekexp;
		if (savings + earnings > 0) ++numweeks;
	}
	
	cout << numweeks << endl;
}
