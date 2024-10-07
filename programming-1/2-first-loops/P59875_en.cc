//TOP TO BOTTOM

//The program reads two numbers x and y, and prints all numbers between x and 
//y (or between y and x), in decreasing order.

//Input consists of two integer numbers x and y.
//Output: Print all integer numbers between x and y (or between y and x), in 
//decreasing order.

#include <iostream>

using namespace std;

int main() {
    int first, second; //integer numbers
    cin >> first >> second;
    
    //Sees which is the bigger number
    int max = first;
    int min = second;
    if (second > first) {
        max = second;
        min = first;
    }  
    
    //Prints all the numbers in decreasing order
    for (int i = max; i >= min; --i) {
        cout << i << endl;
    } 
}
