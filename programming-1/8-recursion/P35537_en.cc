//INCREASING NUMBERS

//Write a recursive function that tells if a natural number n is increasing or 
//not. We say that a natural number is increasing if every digit is less than 
//or equal to the digit which is on its right (if any).

//Input is a natural number.
//Output: prints true if the number is increasing. Otherwhise, prints false.

#include <iostream>

using namespace std;

//Sees if a number is increasing or not.
//Pre: a natural number.
//Post: returns true if the number is increasing. Otherwhise, returns false.
bool is_increasing(int n) {
    bool result = false;
    
    //Base conditions
    if (n < 10) result = true;
    else if (n % 10 < (n / 10) % 10) result = false;
    //Recursive conditions
    else result = is_increasing(n / 10);
    
    return result;
}

int main() {
    int num;
    
    while (cin >> num) {
        if (is_increasing(num)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}
