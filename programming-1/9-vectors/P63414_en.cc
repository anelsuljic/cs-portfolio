//COUNTING FREQUENCES

//Write a program that reads a sequence of natural numbers and that prints,
//for each one, how many times it appears.

//Input consists of a natural number n, followed by n natural numbers between
//1000000000 and 1000001000 (both included).
//Output: For each number x that appears in the sequence, print how many times
//it appears, following the format of the example. The output must be sorted
//in increasing order by x.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of integer numbers and stores it into a vector
//Pre: -----------
//Post: returns Seq.
vector<int> read_data() {
    int size;
    cin >> size;

    vector<int> Seq(size);

    for (int i = 0; i < size; ++i) {
        cin >> Seq[i];
    }

    return Seq;
}

//Calculates how many times the numbers between 1000000000 and 1000001000
//included appears in the sequence.
//Pre: a vector of integer numbers.
//Post: returns Freq.
vector<int> frequences(const vector<int> &Seq) {
    //A vector to store the frequences of every number
    vector<int> Freq(1001, 0);

    int sizeSeq = Seq.size();

    //Stores in freq how many times every element of Seq appears
    for (int i = 0; i < sizeSeq; ++i) {
        ++Freq[Seq[i] - 1000000000];
    }

    return Freq;
}

//Prints in increasing order every number of the sequence and how many times
//it appears.
//Pre: a vector of frequences.
//Post: ------------
void print_data(const vector<int> &Freq) {
    int sizeFreq = Freq.size();

    //Prints only if the frequence is bigger than 0.
    for (int i = 0; i < sizeFreq; ++i) {
        if (Freq[i] > 0) {
            cout << i + 1000000000 << ' ' << ':' << ' ' << Freq[i] << endl;
        }
    }
}

int main() {
    vector<int> Seq = read_data();
    vector<int> Freq = frequences(Seq);
    print_data(Freq);
}
