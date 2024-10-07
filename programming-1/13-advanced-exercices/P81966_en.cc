// DICHOTOMIC SEARCH

#include <iostream>
#include <vector>

using namespace std;

int position(double x, const vector<double>& v, int left, int right)
// Pre: v is sorted in strictly increasing order. Moreover, we have 0 ≤ left ≤ 
// size of v and −1 ≤ right < size of v.
// Post: returns the position of x if it belongs to v or -1 if it doesn't 
// belong.
{
    int pos = -1;

    if (left <= right) {
        pos = (left + right) / 2;
        if (v[pos] > x) pos = position(x, v, left, pos - 1);
        else if (v[pos] < x) pos = position(x, v, pos + 1, right);
    }

    return pos;
}