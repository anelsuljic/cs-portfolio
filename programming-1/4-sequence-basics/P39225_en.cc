//I-TH(1)

//Write a program that, given an integer number i and a sequence of natural 
//numbers x1, …, xn, prints xi.

//Input begins with a number i, followed by the sequence x1, …, xn ended with 
//−1. It is known that 1 ≤ i ≤ n.
//Output: Print the content of the position i as it is shown in the examples.

#include <iostream>

using namespace std;

int main() {
    int position, num;
    cin >> position >> num;
    
    int counter = 1;
    
    while (counter < position and num != -1) {
        cin >> num;
        ++counter;
    }
    
    cout << "At the position " << position << " there is a(n) " << num << '.' 
         << endl;
}
