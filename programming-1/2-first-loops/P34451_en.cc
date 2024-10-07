//CONTROL C201C

//The program reads an integer strictly positive x and a sequence of 
//integers, and prints how many elements of the sequence are multiple of x.

//The input is an integer x > 0 followed by a sequence of integers.
//Output: print the number of elements of the sequence that are multiple of x.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;
   
    int elemseq; //integer number
    int counter = 0;
    
    //Reads the sequence and looks for multiples of num
    while (cin >> elemseq) {
        if (elemseq % num == 0) ++counter;
    }
    
    cout << counter << endl;    
}
