//RECURSIVE FACTORIAL

//Write a function that returns n!. Solve this problem recursively.
//Input is an integer number such as 0 <= num <= 12.
//Output: prints the factorial of num.

#include <iostream>

using namespace std;

//Calculates the factorial of an integer number.
//Pre: 0 <= n <= 12.
//Post: returns result.
int factorial(int n) {
    int result = 0;

    //Base condition
    if (n == 0) result = 1;
    //Recursive condition
    else result = n * factorial(n - 1);

    return result;
}

int main() {
    int num;

    while (cin >> num) {
        cout << factorial(num) << endl;
    }
}
