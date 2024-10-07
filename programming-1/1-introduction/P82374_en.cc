//CONTROL C102A

//Given five integers x,a,b,c,d, the program determines if x∈[a,b]∪[c,d].

//The input is five integers x,a,b,c,d.
//The output is a line with the text “yes” if x∈[a,b]∪[c,d] and the text “no”
//otherwise.

#include <iostream>

using namespace std;

int main() {
    int num, firstelem, secondelem, thirdelem, fourthelem; //integer numbers
    cin >> num >> firstelem >> secondelem >> thirdelem >> fourthelem;

    //Sees if num belongs to the union of both intervals.
    bool belongs = false;
    //num belongs to the intervals
    belongs = (num >= firstelem and num <= secondelem) or (num >= thirdelem
              and num <= fourthelem);

    if (belongs) cout << "yes" << endl;
    else cout << "no" << endl;
}
