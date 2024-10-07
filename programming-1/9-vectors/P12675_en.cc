//COMMON ELEMENTS

//Write a function that given two vectors X and Y in increasing order,
//returns the number of common elements in the two vectors, that is, the
//number of integer numbers a such that a=X[i]=Y[j] for any i and j.

//Input consists of a sequence of pairs of vectors, preceded by their size.
//Output: prints how many common elements has every pair of vectors.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of integer numbers and stores it into a vector.
//Pre: an empty vector of integers.
//Post: returns Seq.
void read_data(vector<int> &Seq) {
    int sizeVec = Seq.size();

    //Reads the sequence and stores it into Seq.
    for (int i = 0; i < sizeVec; ++i) {
        cin >> Seq[i];
    }
}

//Looks how many common elements has a pair of two vectors of integers.
//Pre: two vectors of integers, X and Y, in increasing order.
//Post: returns common.
int common_elements(const vector<int>& X, const vector<int>& Y) {
    int sizeX = X.size();
    int sizeY = Y.size();

    //Two counters to treat every elements of both vectors.
    int posX = 0;
    int posY = 0;

    int common = 0;

    //Looks for common elements
    while (posX < sizeX and posY < sizeY) {
        //Inv: common increases when a common element is found
        if (X[posX] == Y[posY]) {
            ++common;
            ++posX;
            ++posY;
        }
        else if (X[posX] > Y[posY]) ++posY;
        else ++posX;
    }

    return common;
}

int main() {
    int sizeX, sizeY; //natural numbers

    while (cin >> sizeX >> sizeY) {
        //Reads two pairs of vectors
        vector<int> X(sizeX);
        read_data(X);
        vector<int> Y(sizeY);
        read_data(Y);

        cout << common_elements(X, Y) << endl;
    }
}
