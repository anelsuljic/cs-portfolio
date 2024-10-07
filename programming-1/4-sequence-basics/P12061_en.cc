//WORDS BETWEEN TWO WORDS

//Given a sequence of words, the program prints the number of words between 
//the word “beginning” and the word “end”. If the word “beginning”, the word 
//“end” or both words are missing, or if they appear in inverse order, tell 
//so.

//Input consists of several words. The words “beginning” and “end” appear, at 
//most, once.
//Output: Print the number of words between the word “beginning” and the word 
//“end”, if these appear in this order. Otherwise, print “wrong sequence”.

#include <iostream>

using namespace std;

int main() {
    string word;
    
    //The words "beginning" and "end" didn't appear yet.
    bool beginning = false;
    bool end = false;

    int counter = 0;
    
    //Counts the number of words between "beginning" and "end"
    while (not end and cin >> word) {
        if (word == "beginning") beginning = true;
        else if (word == "end") end = true;
        else if (beginning) ++counter;
    }
    
    //Checks if the sequence is correct or not
    if (not beginning or not end) cout << "wrong sequence" << endl;
    else cout << counter << endl;
}
