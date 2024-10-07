//EQUAL TO THE SUM OF THE REST (II)

//Write a program that, given a sequence of integer numbers, tells if there is
//any number equal to the sum of the rest.

//Input contains several cases. Each case begins with a number nâ‰¥1 followed by
//n integer numbers.
//Output: For each case, tell if it has a number equal to the sum of the rest.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of integer number and stores it into a vector, and sums its
//elements
//Pre: an empty vector of integers.
//Post: returns Vec and sum.
void read_data(vector<int> &Vec, int &sum) {
    int sizeVec = Vec.size();
    sum = 0;
    //Reads the sequence
    for (int i = 0; i < sizeVec; ++i) {
        cin >> Vec[i];
        sum += Vec[i];
    }
}

//Tells if a vector contains any element equal to the sum of the rest
//Pre: a vector of integer numbers and the sum of its elements.
//Post: return correct.
bool found(const vector<int> &Vec, const int &sum) {
    bool correct = false;
    int sizeVec = Vec.size();

    int pos = 0;
    while (not correct and pos < sizeVec) {
        correct = (sum - Vec[pos]) == Vec[pos];
        ++pos;
    }
    return correct;
}

int main() {
    int size; //natural number
    while (cin >> size) {
        vector<int> Vec(size);
        int sum;
        read_data(Vec, sum);

        if (found(Vec, sum)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
