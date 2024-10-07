//REVERSE OF SEQUENCES

//Write a program that reads sequences of integer numbers, and prints each one
//reversing the order of its elements.

//Input consists of several sequences. Each sequence consists of a natural
//number n, followed by n integer numbers.
//Output: Print each sequence in reverse order in a line.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of integer numbers and stores it into a vector.
//Pre: an empty vector of integers.
//Post: returns Seq.
void read_vector(vector<int> &Seq) {
    int sizeVec = Seq.size();

    for (int i = 0; i < sizeVec; ++i) {
        cin >> Seq[i];
    }
}

//Reverses and prints the elements of a given vector.
//Pre: a vector of integers.
//Post: -----------
void reverses_sequence(const vector<int> &Seq) {
    int lastElem = Seq.size() - 1;

    bool first = true;

    for (int i = lastElem; i >= 0; --i) {
        //To avoid an unnecessary first space
        if (first) {
            cout << Seq[i];
            first = false;
        }

        else cout << ' ' << Seq[i];
    }
    cout << endl;
}

int main() {
    int size; //natural number

    while (cin >> size) {
        vector<int> Seq(size);
        read_vector(Seq);
        reverses_sequence(Seq);
    }
}
