//RAMPS

//Write a program indicating the positions with a ramp and the number of pairs
//(i,j) with i<j corresponding to positions with a ramp and potentially
//conflictive.

//The input is formed by a non-empty sequence of cases. Each case is described
//by an integer n≥ 3 followed by the n integer values of the corresponding
//vector.
//Output: Print, for each case, the positions having a ramp and the number of
//pairs of positions (i,j) with i<j having a ramp and potentially conflictive.

#include <iostream>
#include <vector>

using namespace std;

//Reads a sequence of integer numbers and stores it into a vector.
//Pre: an empty vector of integer numbers.
//Post: returns Vec.
void read_data(vector<int> &Vec) {
    int sizeVec = Vec.size();

    //Reads the sequence
    for (int i = 0; i < sizeVec; ++i) {
        cin >> Vec[i];
    }
}

//Sees in which positions of a vector of integers there is a ramp.
//Pre: a vector of integer numbers.
//Post: returns a vector of booleans, Ramps, where its positions are true if
//in that position there is a ramp. Otherwhise, the position is false.
vector<bool> ramps_pos(const vector<int> &Seq) {
    int sizeSeq = Seq.size();

    //Stores the results into Ramps
    vector<bool> Ramps(sizeSeq, false);

    //Looks where there is a ramp
    for (int i = 0; i < sizeSeq - 2; ++i) {
        if (Seq[i] < Seq[i + 1] and Seq[i + 1] < Seq[i + 2]) Ramps[i] = true;
        else if (Seq[i] > Seq[i + 1] and Seq[i + 1] > Seq[i + 2]) {
            Ramps[i] = true;
        }
    }

    return Ramps;
}

//Sees which positions of ramps are potentially conflictive.
//Pre: a vector of booleans, Ramps.
//Post: returns counter.
int pot_conflictive(const vector<bool> &Ramps) {
    int size = Ramps.size();

    int counter = 0;

    //Treats every position
    for (int i = 0; i < size - 2; ++i) {
        if (Ramps[i]) {
            if (Ramps[i + 1]) ++counter;
            if (Ramps[i + 2]) ++counter;
        }
    }
    //Last positions
    if (Ramps[size - 2] and Ramps[size - 1]) ++counter;

    return counter;
}

//Prints the positions with a ramp and how many of them are potentially
//conflictive
//Pre: a vector of booleans, Ramps.
//Post: --------
void print_data(const vector<bool> &Ramps) {
    cout << "positions with a ramp:";
    //Prints the positions with a ramp
    int size = Ramps.size();
    for (int i = 0; i < size; ++i) {
        if (Ramps[i]) cout << ' ' << i;
    }
    cout << endl;

    //Prints the number of positions potentially conflictive
    cout << "potentially conflictive: " << pot_conflictive(Ramps) << endl;

    //Adds a line with three scripts
    cout << "---" << endl;
}

int main() {
    int size; //natural number

    while (cin >> size) {
        if (size >= 3) {
            vector<int> Seq(size);
            read_data(Seq);
            vector<bool> Ramps = ramps_pos(Seq);
            print_data(Ramps);
        }
        else {
            cout << "positions with a ramp:" << endl;
            cout << "potentially conflictive: 0" << endl;
            cout << "---" << endl;
        }
    }
}
