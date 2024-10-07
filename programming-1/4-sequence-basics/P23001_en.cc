//CONSECUTIVE REPEATED WORDS

//Given a sequence of words, the program prints the length of the longest 
//consecutive subsequence that only contains the first word.

//Input consists of a non-empty sequence of words.
//Output: Print the number of words of the longest consecutive subsequence 
//that only contains the first word.

#include <iostream>

using namespace std;

int main() {
    string first; //Reference word
    cin >> first;
    
    string act; //Rest of words
    int counter = 1;
    int max = 1;
   
    while (cin >> act) {
        //Counter only increases when words are the same consecutively.
        if (act == first) ++counter;
        else counter = 0;
        if (counter > max) max = counter;
    }
    
    cout << max << endl;
}
