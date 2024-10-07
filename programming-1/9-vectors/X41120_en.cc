//VECTOR OF MOUNTAINS

//Write a program that, given a mountainous profile represented by a vector,
//calculates the number of peaks and which of these peaks are higher than the
//last visited peak of the hike.

//The input is formed by a natural n ≥ 3 indicating the number of points in
//the mountainous profile. Following, there are the n heights registred at
//those points. The heights are integer numbers.
//Output: Indicate the total number of mountain peaks for the profile
//described in the input, and their height. Then print the height of those
//peaks that are higher than the last peak in the described profile. The
//cases of a profile not having any peak, or not having peaks higher than the
//last one, should be noted conveniently.

#include <iostream>
#include <vector>

using namespace std;

//Reads the size of a sequence of integer numbers and reads the whole
//sequence and stores it into a vector.
//Pre: --------
//Post: returns Vec.
vector<int> read_data() {
    int size; //natural number
    cin >> size;

    //Vector of size elements
    vector<int> Vec(size);

    //Reads the sequence
    for (int i = 0; i < size; ++i) {
        cin >> Vec[i];
    }

    return Vec;
}

//Searches the mountain peaks of a vector of heights and stores those peaks
//into another vector.
//Pre: a vector of integer numbers, Heights.
//Post: returns a vector of integers, Peaks.
vector<int> obtain_peaks(const vector<int> &Heights) {
    int sizeHeights = Heights.size();
    vector<int> Peaks;

    //Stores all the Peaks into a vector
    for (int i = 1; i < sizeHeights - 1; ++i) {
        if (Heights[i] > Heights[i - 1] and Heights[i] > Heights[i + 1]) {
            Peaks.push_back(Heights[i]);
        }
    }

    return Peaks;
}

//Prints the total number of peaks, followed by the peaks.
//Pre: a vector of integer numbers, Peaks.
//Post: --------
void print_all_peaks(const vector<int> &Peaks) {
    int totalPeaks = Peaks.size();

    //Prints the number of peaks, followed by the peaks.
    cout << totalPeaks << ':';
    for (int i = 0; i < totalPeaks; ++i) {
        cout << ' ' << Peaks[i];
    }
    cout << endl;
}

//Prints all the peaks greater than the last peak visited.
//Pre: a vector of integer numbers, Peaks.
//Post: --------
void print_greatest_peaks(const vector<int> &Peaks) {
    int lastPeak = Peaks.size() - 1;
    bool greatest_peaks = false;

    //Prints the peaks greater than Peaks[lastPeak].
    for (int i = 0; i < lastPeak; ++i) {
        if (Peaks[i] > Peaks[lastPeak]) {
            //First greater peak
            if (not greatest_peaks) {
                cout << Peaks[i];
                greatest_peaks = true;
            }
            //Rest of peaks, if there are.
            else {
                cout << ' ' << Peaks[i];
            }
        }
    }

    if (not greatest_peaks) cout << '-';
    cout << endl;
}

int main() {
    vector<int> Heights = read_data();
    vector<int> Peaks = obtain_peaks(Heights);
    print_all_peaks(Peaks);
    print_greatest_peaks(Peaks);
}
