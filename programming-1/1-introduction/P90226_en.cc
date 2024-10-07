//COMPARISON OF WORDS

//The program reads two words and tells their lexicographic order.

//Input consists of two words a and b, made up of only lowercase letters.
//Output: print a line telling if a < b, a > b or a = b, following the format
//of the examples exactly.

#include <iostream>

using namespace std;

int main() {
    string firstword, secondword; //lowercase strings
    cin >> firstword >> secondword;

    //firstword < secondword
    if (firstword < secondword) cout << firstword << ' ' << '<' << ' ' <<
        secondword << endl;

    //firstword > secondword
    else if (firstword > secondword) cout << firstword << ' ' << '>' << ' '
        << secondword << endl;

    //firstword = secondword
    else cout << firstword << ' ' << '=' << ' ' << secondword << endl;
}
