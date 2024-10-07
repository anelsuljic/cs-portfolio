//PREFECT NUMBERS

//Write a function that tells if a natural n is perfect. A natural number is
//called perfect if it is equal to the sum of all its divisors except itself.

//Input is a natural number.
//Output: prints true if the number is perfect.

#include <iostream>

using namespace std;

//Sums the divisors of a number
//Pre: a natural number
//Post: the sum of its divisors
int sum_divisors(int num) {
    int sum = 1;

    for (int i = 2; i * i <= num; ++i) {
        if (i * i == num) sum += i;
        else if (num % i == 0) sum += i + num / i;
    }

    return sum;
}

//Sees if a number is perfect.
//Pre: a natural number.
//Post: true if the number is perfect. Otherwhise, false.
bool is_perfect(int n) {
    bool result = false;

    if (n < 6) result = false;
    else result = n == sum_divisors(n);

    return result;
}

int main() {
    int num;

    while (cin >> num) {
        if (is_perfect(num)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}
