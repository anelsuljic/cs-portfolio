//COMPUTING AREAS

//The program reads several descriptions of rectangles and circles, and for 
//each one prints its corresponding area.

//Input begins with a number n, followed by n descriptions. If of a rectangle, 
//we have the word “rectangle” followed by two strictly positive real 
//numbers: its length and its width. If of a circle, we have the word 
//“circle” followed by a strictly positive real number: its radius.
//Output: For each description, print its area with 6 digits after the decimal 
//point.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int numelemseq; //natural number
    cin >> numelemseq;
    
    //Reads every description
    for (int i = 0; i < numelemseq; ++i) {
        string fig; 
        cin >> fig;
        
        double area;
        if (fig == "rectangle") {
            double lenght, width; //natural numbers
            cin >> lenght >> width;
            
            area = lenght * width;
        }
        
        else { //fig = "circle"
            double rad; //natural numbers
            cin >> rad;
            
            area = M_PI * rad * rad;
        }
        
        cout.setf(ios::fixed);
        cout.precision(6);
        
        cout << area << endl;
    }
}
