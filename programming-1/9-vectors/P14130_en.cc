//EQUAL TO THE LAST ONE

//Write a program that reads a non-empty sequence of integer numbers, and
//tells how many of them are equal to the last one.

//Input consists of a natural number n > 0, followed by n integer numbers.
//Output: Print the number of elements that are equal to the last one, this
//one excluded.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of natural numbers and stores it into a vector.
//Pre: a vector with empty elements.
//Post: returns Seq.
void reads_vector(vector<int> &Seq) {
    int sizeVec = Seq.size();

    for (int i = 0; i < sizeVec; ++i) {
        cin >> Seq[i];
    }
}

//Sees how many elements of a given vector are equal to the last element of
//that vector
//Pre: a vector of integer numbers
//Post: returns counter.
int equal_last_one(const vector<int> &Seq) {
    int lastelem = Seq.size() - 1;

    int counter = 0;
    //Looks for the same elements as the last elem of the vector
    for (int i = 0; i < lastelem; ++i) {
        if (Seq[i] == Seq[lastelem]) ++counter;
    }

    return counter;
}

int main() {
    int size; //natural number
    cin >> size;

    //Reads a sequence of integer numbers
    vector<int> Seq(size);
    reads_vector(Seq);

    cout << equal_last_one(Seq) << endl;
}
