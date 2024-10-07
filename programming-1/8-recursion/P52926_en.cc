//GIRANT UNA LLISTA DE PARAULES (2)

//Write a program that reads a sequence of words until the first appearance of
//the word “end”, and prints it reversed.

//Input consists of a sequence of words. At least one is “end”.
//Output: Print all the words of the original sequence until the first
//appearance of “end”, in reverse order, and one per line.

#include <iostream>

using namespace std;

//Reads and reverses a sequence of words
//Pre: ---------
//Post: ---------
void reversing_words() {
    string word;
    cin >> word;

    if (word != "end") {
        reversing_words();

        cout << word << endl;
    }
}

int main() {
    reversing_words();
}
