//CONCATENATION OF VECTORS

//Write a function that returns the concatenation of v1 and v2. That is, you
//must return a vector with the elements of v1 followed by the elements of v2.

//Input consist of a sequence of two natural numbers sizeX and sizeY,
//followed by sizeX integer numbers and sizeY integers numbers.
//Output: prints the concatenation of two vectors.

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

//Merges two vectors into one vector.
//Pre: two vectors of integer numbers.
//Post: returns Concatenation.
vector<int> concatenation(const vector<int>& v1, const vector<int>& v2) {
    vector<int> Concatenation;

    //Copies the first vector
    Concatenation = v1;

    //Adds the elements of v2
    int sizeV2 = v2.size();

    for (int i = 0; i < sizeV2; ++i) {
        Concatenation.push_back(v2[i]);
    }

    return Concatenation;
}

//Prints the elements of a given vector.
//Pre: a vector of integer numbers.
//Post: ----------
void print_data(const vector<int> &Vec) {
    int sizeVec = Vec.size();

    //Prints the elements of Vec
    for (int i = 0; i < sizeVec; ++i) {
        cout << Vec[i];
    }
}

int main() {
    int sizeX, sizeY; //natural numbers

    while (cin >> sizeX >> sizeY) {
        //Reads two pairs of vectors
        vector<int> X(sizeX);
        read_data(X);
        vector<int> Y(sizeY);
        read_data(Y);

        //Merges the two vectors.
        vector<int> Merged = concatenation(X, Y);
        //Prints the final vector
        print_data(Merged);
        cout << endl;
    }
}
