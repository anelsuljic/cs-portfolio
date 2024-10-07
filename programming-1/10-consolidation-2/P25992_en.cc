// SEPARATED SORT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparation function for sort method.
bool cmp(int a, int b)
// Pre: true.
// Post: true if a > b. Otherwhise, false.
{
    return a > b;
}

// Writes to the standard output channel the content of a vector of integers.
void write(const vector<int> &Vec)
// Pre: true.
// Post: the content of Vec is written to the standard output channel, with 
// every element separated by a space.
{
    int size = Vec.size();
    for (unsigned int i = 0; i < size; ++i) {
        if (i != 0) cout << ' ';
        cout << Vec[i];
    }
    cout << endl;
}

// Given a sequence of natural numbers, first, prints the even numbers in 
// increasing order, and then the odd numbers in decreasing order.
int main()
// Input: zero or more cases. Each case consists of a line with at most 1000 
// natural numbers strictly positive. Each line ends with a 0 that indicates 
// the end.
// Output: for each case, prints in a line the even numbers in increasing 
// order, and in the following line the odd numbers in decreasing order.
{
    unsigned int num;    // Natural number
    while (cin >> num) {
        vector<int> E, O;
        while (num != 0) {
            if (num % 2 == 0) E.push_back(num);
            else O.push_back(num);

            cin >> num;
        }

        sort(E.begin(), E.end());
        write(E);
        sort(O.begin(), O.end(), cmp);
        write(O);
    }
}