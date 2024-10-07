// SQUARES (1)

// The program reads a sequence of natural numbers between 1 and 9, and for
// every number (call it "n"), it prints to the std output channel squares
// with n² n's.

// Input: a sequence of natural numbers between 1 and 9.
// Output: for every number "n", prints a square of size n² full of n's.
//         Every square is separated by an empty space.

// Example of input and output (only one element of the sequence):
//
// Inp: 3
// Out: 333
//      333
//      333


#include <iostream>
using namespace std;


int main()
{
    int num;    // natural number between 1 and 9.
    bool first = true;
    
    while (cin >> num) {
        // Inv 1: the std output channel contains all the squares printed from 
        //      the elements already treated.

        if (not first) cout << endl;
        else first = false;
        
        for (int i = 1; i <= num; ++i) {
            // Inv 2: the std output channel contains all the information from
            //        "Inv 1" printed, plus i-1 lines of "num" num's printed.

            for (int j = 1; j <= num; ++j) {
                // Inv 3: the std output channel contains all the information
                //        from "Inv 2" printed, plus j-1 num's printed in line
                //        "i".

                cout << num;
            }
            cout << endl;
        }
    }
}