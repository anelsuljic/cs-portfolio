//LINES IN ORDER (2)

//Write a program that, given a sequence of lines with words, tells which is 
//the last line that has the words in increasing (lexicographic) order.

//Input consists of a sequence of lines with words. Each line begins with a 
//number n, followed by n words made up of only lowercase letters.
//Output: Print the index of the last line with the words in (not necessary 
//strictly) increasing order. If there is no such line, tell so. Follow the 
//format of the examples.

#include <iostream>

using namespace std;

int main() {
    int numelem; //Natural number
    
    int line = 1; //Lines counter
    int position = 0; //Last line in increasing order
    
    while (cin >> numelem) {
        if (numelem > 0) {
            string word; //First word
            cin >> word;
            
            bool inc_order = true;
            int counter = 1;
        
            while (inc_order and counter < numelem) {
                string act; //Rest of words
                cin >> act;
            
                if (act < word) inc_order = false;
            
                word = act;
            
                ++counter;
            }
            if (inc_order) position = line;
    
            while (counter < numelem) {
            cin >> word;
            
            ++counter;
            }
        }
        else position = line;
        
        ++line;
    }
    
    if (position != 0) cout << "The last line in increasing order is " << 
                            position << '.' << endl;
    else cout << "There is no line in increasing order." << endl;
}
