//ROUNDING

//The program reads a real number x≥0 and prints ⌊ x ⌋ (the floor of x), ⌈ x ⌉
//(the ceiling of x), and the rounding of x.

//Input consists of a real number x ≥ 0.
//Output: Print the floor of x, the ceiling of x, and the integer number
//closer to x (⌈ x ⌉ if there is a tie).

#include <iostream>

using namespace std;

int main() {
    double num; //real number >= 0
    cin >> num;

    double decimal = num - int(num);
    //Floor of num
    cout << int(num) << ' ';

    //Ceiling of num
    if (decimal != 0) cout << int(num) + 1 << ' ';
    else cout << int(num) << ' ';

    //Rounding of num
    if (decimal >= 0.5) cout << int(num) + 1 << endl;
    else cout << int(num) << endl;
}
