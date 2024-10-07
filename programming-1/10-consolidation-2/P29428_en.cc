//F002A. INFIXES

//Your task is to write a program that reads a sequence of words and prints,
//for each word, all the other words of the sequence contained in it.

//Input consists in a natural number n followed by n different words p1,…,pn.
//Output: The program has to print a line for each p1,…,pn in this order.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Reads a sequence of integers and stores it into a vector.
//Pre: an empty vector of strings Words.
//Post: returns Words.
void read_data(vector<string> &Words) {
    int sizeVec = Words.size();

    //Reads the sequence
    for (int i = 0; i < sizeVec; ++i) {
        cin >> Words[i];
    }
}

//Given two strings, sees if the second one is a subtring of the first one.
//Pre: two word strings.
//Post: returns true if the second string is inside the first.
bool contains(string word, string subword) {
    int sizeW = word.size();
    int sizeSubword = subword.size();

    //Two counters to treat the position of every word
    int posWord = 0;
    int posSubword = 0;

    while (posWord + sizeSubword <= sizeW and posSubword < sizeSubword) {
        //If the condition is not true, it restarts the counter posSubword.
        if (word[posWord + posSubword] == subword[posSubword]) ++posSubword;
        else {
            posSubword = 0;
            ++posWord;
        }
    }

    return posSubword == sizeSubword;
}

//Sees how many infixes has every word of a vector, and prints all of them.
//Pre: a vector of strings: "Words".
//Post: ---------------
void infixes(const vector<string> &Words) {
    int sizeVec = Words.size();

    //Looks how many infixes has every word
    for (int i = 0; i < sizeVec; ++i) {
        cout << Words[i] << ':';

        //Looks which word of the sequence in an infixe of Words[i]
        for (int j = 0; j < sizeVec; ++j) {
            if (contains(Words[i], Words[j])) {
                cout << ' ' << Words[j];
            }
        }

        cout << endl;
    }
}

int main() {
    int size; //natural number
    cin >> size;

    //Stores the sequence into a vector
    vector<string> Words(size);
    read_data(Words);

    infixes(Words);
}
