//REVERSING WORDS (2)

//Write a program that reads words, and prints them in reverse order,
//reversing also the order of the characters of each word.

//Input consists of a natural number n, followed by n words.
//Output: Print the words in reverse order, one per line, and with the
//characters inside each word reversed.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Reads a sequence of integer numbers and stores it into a vector.
//Pre: an empty vector of integers.
//Post: returns Seq.
void read_vector(vector<string> &Seq) {
    int sizeVec = Seq.size();

    for (int i = 0; i < sizeVec; ++i) {
        cin >> Seq[i];
    }
}

//Reverses and prints a sequence of characters
//Pre: a string
//Post: --------
void reversing_words(string &seqChar) {
    int sizeString = seqChar.size();

    for (int i = sizeString - 1; i >= 0; --i) {
        cout << seqChar[i];
    }
    cout << endl;
}

int main() {
    int size; //natural number
    cin >> size;

    //Stores the sequence into a vector of words
    vector<string> Words(size);
    read_vector(Words);

    //Reverses the sequence and its content inside^
    for (int i = size - 1; i >= 0; --i) {
        reversing_words(Words[i]);
    }
}
