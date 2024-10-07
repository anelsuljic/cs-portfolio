//FUNCTION TO FATTEN NUMBERS

//In this problem, given any natural number x with n digits x1 … xn, we say 
//that y = y1 … yn is the result of fattening x if, for every i between 1 and 
//n, yi = max{x1, …, xi}.

//Input is a natural number.
//Output: print the fattened number of a natural number.

#include <iostream>

using namespace std;

//Calculates the maximum of two numbers
//Pre: a natural number.
//Post: returns the maximum number.
int max_2(int a, int b) {
    int result = a;
    if (b > a) result = b;
    
    return result;
}

//Fattens a natural number
//Pre: It holds 0 < x < 10exp9.
//Post: returns the fattened number.
int fatten(int x) {
    int result = 0;
    if (x < 10) result = x;
    else result = fatten(x / 10) * 10 + max_2(fatten(x / 10) % 10, x % 10);
    
    return result;
}

int main() {
    int num;
    
    while (cin >> num) {
        cout << fatten(num) << endl;
    }
}
