//AVERAGE

//The program reads a sequence of numbers and prints their average.

//Input consists of a non-empty sequence of strictly positive real numbers.
//Print the average of the numbers with 2 digits after the decimal point.

#include <iostream>

using namespace std;

int main() {
    double elemseq; //real number strictly positive
    
    double sum = 0;
    int counter = 0;
    
    //Reads and sum all the elements
    while (cin >> elemseq) {
        ++counter;
        sum += elemseq;
    }
    
    //Calculates the average
    double average;
    average = sum / counter;
    
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << average << endl;
}
