//REVERSING A LIST OF WORDS

//The program reads a sequence of words and prints it in reverse order.

//Input consists of a sequence of words.
//Output: Print the words of the original sequence, in reverse order, and one 
//per line.

#include <iostream>

using namespace std;

//Reads and reverses a list of words
//Pre: -------
//Post: -------
void reversing_words() {
    string word;
    
    if (cin >> word) {
        reversing_words();
        
        cout << word << endl;
    }
}

int main() {
    reversing_words();
}
