//PARENTHESES

//Given a sequence made up of only ‘(’ and ‘)’, the program tells if the 
//parentheses close correctly.

//Input consists of a sequence of parentheses.
//Output: Print “yes” or “no”, depending on whether the parentheses close 
//correctly or not.

#include <iostream>

using namespace std;

int main() {
    char parentheses;
    
    int counter = 0;
    //Sees how many opened/closed parentheses are.
    while (counter >= 0 and cin >> parentheses) {
        if (parentheses == '(') ++counter;
        else --counter;
    }
    
    //Checks if the parentheses are closed correctly.
    if (counter == 0) cout << "yes" << endl;
    else cout << "no" << endl;
}
