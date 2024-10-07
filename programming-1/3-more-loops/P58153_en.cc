//HARMONIC NUMBERS(2)

//The program reads pairs of numbers n and m with n ≥ m, and for each pair 
//prints Hn − Hm.

//Input consists of several pairs of natural numbers n and m such that n ≥ m.
//Output: for every pair, print Hn − Hm with 10 digits after the decimal 
//point.

#include <iostream>

using namespace std;

int main() {
    int first, second; //natural numbers. first >= second.
    
    //Reads every pair of numbers
    while (cin >> first >> second) {

        //Makes the resultant harmonic.
        double result = 0;
        for (int i = second + 1; i < first + 1; ++i) {
            result += 1 / double(i);
        }
        
        cout.setf(ios::fixed);
        cout.precision(10);
        
        cout << result << endl;
    }
    
}
