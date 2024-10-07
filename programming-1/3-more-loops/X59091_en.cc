//RECTANGLES (2)

//The program prints n× m rectangles. Prints each rectangle in an independent 
//way, fill it up with 9, followed by 8, …followed by 0, etc.

//The input consists of several pairs of natural numbers.
//Output: For every pair (n,m), print a rectangle of size n × m filled with 
//9,8,…0, 9, …. Separate two rectangles with an empty line.

#include <iostream>

using namespace std;

int main() {
    int base, height; //natural numbers
    bool first = true;
    
    //Reads every pair
    while (cin >> base >> height) {
        if (not first) cout << endl;
        else first = false;
        
        int num = 9;
        
        //Prints every line
        for (int i = 0; i < base; ++i) {
            //Prints every column
            for (int j = 0; j < height; ++j) {
                cout << num;
                
                --num;
                if (num < 0) num = 9;
            }
            
            cout << endl;
        }
    }
}
