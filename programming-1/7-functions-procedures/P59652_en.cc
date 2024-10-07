//READ A RATIONAL NUMBER (1)

//Write a procedure to read a rational number given in the form 
//“numerator”/“denominator”, and store these two values in num and den, 
//respectively. Additionally, you must remove all common factors from num and 
//den. 

//Input: two numbers num and den, and the character '/', such as "num/den".
//Output: prints num and den.

#include <iostream>

using namespace std;

//Calculates the greater common divisor of two numbers
//Pre: two natural numbers.
//Post: returns maxdiv.
int mcd(int first, int second) {
    while (second != 0) {
        int aux = first % second;
        first = second;
        second = aux;
    }
    
    return first;
}

//Removes the common factors of a rational number (num/den) and stores these 
//two values in num and den.
//Pre: two integer numbers.
//Post: returns num and den.
void read_rational(int &num, int &den) {
    char arrow;
    cin >> num >> arrow >> den;
    //Finds the gratest common divisor
    int div = mcd(num, den);
    
    //Simplifies num and den
    num /= div;
    den /= div;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int num, den;
    read_rational(num, den);
    cout << num << ' ' << den << endl;
  }
}
