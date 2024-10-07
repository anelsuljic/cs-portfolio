//PROCEDIMENT PER AL DÍGIT MÀXIM I MÍNIM

//Escriviu un procediment recursiu void digit_maxim_i_minim(int n, int&
//maxim, int& minim) que deixi en el paràmetre de sortida maxim el dígit més
//gran de n, i deixi en el paràmetre de sortida minim el dígit més petit de n.

//Input is a natural number.
//Output: print the maximum and minimum digit of that number.

#include <iostream>

using namespace std;

//Finds the biggest and the smallest digit of n and stores them in maxim and
//minim, repectively.
//Pre: a natural number.
//Post: returns maxim and minim.
void digit_maxim_i_minim(int n, int& maxim, int& minim) {
    //Basic case
    if (n < 10) {
        maxim = n;
        minim = n;
    }

    //Recursive condition
    else {
        digit_maxim_i_minim(n / 10, maxim, minim);

        if (n % 10 > maxim) maxim = n % 10;
        else if (n % 10 < minim) minim = n % 10;
    }
}

int main() {
    int num;

    while (cin >> num) {
      int max, min;
      digit_maxim_i_minim(num, max, min);
      cout << num << ' ' << max << ' ' << min << endl;
    }
}
