//PAIRS OF A SEQUENCE (1)

//Write a program that reads sequences of natural numbers, and for each one
//tells if it has two elements such that their sum is a prime number.

//Input consists of several sequences, each one in a line. Each sequence
//consists of a natural number n, followed by n natural numbers x1, …, xn.
//Output: For each input sequence, print “yes” or “no” depending on if it is
//possible to find two elements xi and xj (with i ≠ j) such that xi + xj is a
//prime number.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of natural number and stores it into a vector.
//Pre: an empty vector of integer numbers, Seq.
//Post: returns Seq.
void read_data(vector<int> &Seq) {
    int sizeVec = Seq.size();

    //Reads the sequence
    for (int i = 0; i < sizeVec; ++i) {
        cin >> Seq[i];
    }
}

//Sees whether a number is prime or not.
//Pre: a natural number
//Post: returns true if the number is prime. Otherwhise, returns false.
bool is_prime(int num) {
    bool result = true;

    //The smallest prime number is 2.
    int div = 2;

    //Checks if the number is prime
    while (result and div * div <= num) {
        if (num % div == 0) result = false;

        ++div;
    }

    return result;
}

//Sees whether a vector of natural numbers has any pair of elements that are
//prime when we made its sum.
//Pre: a vector of natural numbers.
//Post: returns true if there is any pair prime. Otherwhise, returns false.
bool has_prime_pairs(const vector<int> &Seq) {
    int sizeVec = Seq.size();

    bool result = false;

    //Treats every pair of the vector until we find one which its sum is prime
    int first = 0;

    while (not result and first < sizeVec) {
        int second = 0;

        //Looks for the second operand
        while (not result and second < sizeVec) {
            if (first != second) {
                result = is_prime(Seq[first] + Seq[second]);
            }

            ++second;
        }

        ++first;
    }

    return result;
}

int main() {
    int size; //natural number

    while (cin >> size) {
        vector<int> Seq(size);
        read_data(Seq);

        if (has_prime_pairs(Seq)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
