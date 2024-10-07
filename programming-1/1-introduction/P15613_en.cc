//TEMPERATURES

//The program reads an integer number that represents a temperature given in
//degree Celsius, and tells if the weather is hot, if it’s cold, or if it’s
//ok. It's hot if temp > 30, it's cold if temp < 10, else it's ok. Boils if
//temp >= 100. Freezes if temp <= 0.

//Input consists of an integer number.
//Output: Print a line telling if it’s hot, if it’s cold, or if it’s ok.
//Additionally, print another line if water would boild or if water would
//freeze.

#include <iostream>

using namespace std;

int main() {
    int temp; //integer number
    cin >> temp;

    //Hot temperature
    if (temp > 30) {
        cout << "it's hot" << endl;

        //Water would boil
        if (temp >= 100) cout << "water would boil" << endl;
    }

    //Cold temperature
    else if (temp < 10) {
        cout << "it's cold" << endl;

        //Water would freeze
        if (temp <= 0) cout << "water would freeze" << endl;
    }

    //Normal temperature
    else cout << "it's ok" << endl;
}
