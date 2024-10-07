//PERFECT PRIMES

//Write a recursive function that tells if a natural number n is a perfect 
//prime or not. N is a perfect prime if the infinite sequence n, s(n), 
//s(s(n)), …only contains prime numbers. 

//Input is an integer number bigger or equal to 0.
//Output: prints true wheter the number is a perfect prime. Otherwhise, 
//prints false.

#include <iostream>

using namespace std;

//Sums the digits of a given number
//Pre: an integer number bigger or equal than 0.
//Post: returns the sum of digits of num.
int sum_of_digits(int num) {
    int result = 0;
    
    //Base condition
    if (num < 10) result += num;
    //Recursive case
    else result = num % 10 + sum_of_digits(num / 10);
    
    return result;
}

//Sees if a number is prime or not
//Pre: num >= 0.
//Post: returns true if a number is prime. Otherwhise, returns false.
bool is_prime(int num, int div) {
    bool result = false;
    
    //Base conditions
    if (num < 2) result = false;
    else if (num % div == 0 and num != div) result = false; //This case is for number 2.
    else if (div * div > num) result = true;
    //Recursive condition
    else result = is_prime(num, div + 1);
    
    return result;
}

//Sees if a number is perfect prime or not
//Pre: num >= 0.
//Post: returns true if a number is perfect prime. Otherwhise, returns false.
bool is_perfect_prime(int n) {
    bool result = false;
    
    //Base condition
    if (n < 10) result = is_prime(n, 2);
    //Recursive condition
    else result = is_prime(n, 2) and is_perfect_prime(sum_of_digits(n));
    
    return result;
}

int main() {
    int num; 
    
    while (cin >> num) {
        if (is_perfect_prime(num)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}
