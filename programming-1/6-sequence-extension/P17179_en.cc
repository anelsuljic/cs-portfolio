//STATISTICAL MEASURES

//Write a program that reads non-empty sequences of real numbers and, for each 
//sequence, prints its minimum, its maximum and its average.

//Input consists of a natural number n, followed by n sequences. Each sequence 
//begins with the number of elements m > 0, followed by m real numbers.
//Output: For every sequence, print in a line and with four digits after the 
//decimal point its minimum, its maximum and its average.

#include <iostream>

using namespace std;

int main() {
    int numseq; //Natural number
    cin >> numseq;
    
    //Reads every sequence
    for (int i = 0; i < numseq; ++i) {
        int numelem; //Natural number
        cin >> numelem;
        
        double min = 0;
        double max = 0;
        double average = 0;
        
        //Reads every element of the sequence
        for (int j = 0; j < numelem; ++j) {
            double elem; //Real number
            cin >> elem;
           
            if (j == 0) { //Always puts the first number
                min = elem;
                max = elem;
            }
            else if (elem <= min) min = elem;
            else if (elem >= max) max = elem;
            
            average += elem;
        }
        
        average /= numelem;
        
        cout.setf(ios::fixed);
        cout.precision(4);
        
        cout << min << ' ' << max << ' ' << average << endl;
    }
}
