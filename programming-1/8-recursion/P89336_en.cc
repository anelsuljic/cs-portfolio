//GIRANT UNA LLISTA DE PARAULES(6)

//The program reads a sequence of words and prints, in reverse order, the 
//first half of the list.

//Input consists of a sequence of words.
//Output: If n denotes the total number of words, print the ⌊ n/2 ⌋ first 
//words of the original sequence, in reverse order, and one per line.

#include <iostream>

using namespace std;

//Reads a sequence of words and prints the reversed first half.
//Pre: an integer number >= 0.
//Post: returns counter - 2.
void reversing_words(int &counter) {
    string word;
    
    if (cin >> word) {
        //Recursive condition
        ++counter;
        reversing_words(counter);
        
        //Prints only the first half in reverse order
        if (counter <= 0) cout << word << endl;
        counter -= 2;
    }
}

int main() {
    int counter = 0;
    reversing_words(counter);
}
