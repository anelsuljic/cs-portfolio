//F004B. STABLE PRODUCTS

//The product of x by y is stable if the digits of x and y on one hand, and
//the digits of x * y on the other hand, are the same ones. Your task is to
//write a program that, given a sequence of pairs x and y, prints which bases
//between 2 and 16 (both included) the product x * y is stable for.

//The input is a sequence of pairs of natural numbers x and y. x ≥ 1, y ≥ 1, x
//* and ≤ 109 are fulfilled. You can assume this information as a
//precondition of your procedures.
//Output: For each pair x and y, print which bases the product x * y is stable
//for. If there is not any base, print it. It must print a line feed after
//the output of each case.

#include <iostream>
#include <vector>

using namespace std;

//Look which digits has a number
//Pre: a natural number and its base, and a vector of digit positions and a
//counter.
//Post: returns digits_pos.
void digit_counter(int num, int base, vector<int> &digits_pos, int incr) {
    //Sums incr in every different number of one digit
    while (num > 0) {
        digits_pos[num % base] += incr;
        num /= base;
    }
}

//Sees if two numbers, x and y, have the same digits as x * y.
//Pre: two natural numbers, x and y, and a base.
//Post: returns result.
bool same_digits(int x, int y, int base) {
    vector<int> digits_pos(base, 0);

    //looks for the digits of x and y
    digit_counter(x, base, digits_pos, 1);
    digit_counter(y, base, digits_pos, 1);
    //looks for the digits of x * y
    int aux = x * y;
    digit_counter(aux, base, digits_pos, -1);

    //Looks if there are the same digits between x,y and x * y.
    bool result = true;
    int counter = 0;
    while (result and counter < base) {
        if (digits_pos[counter] != 0) result = false;
        ++counter;
    }

    return result;
}

//Prints a number in it corresponding base.
//Pre: a natural number and a base.
//Post: -------------
void escriu (int num, int base) {
    if (num > 0) {
        //Recursive condition
        int aux = num / base;
        escriu (aux, base);
        //Base condition
        if (num % base < 10) cout << num % base;
        else cout << char('A' + num % base - 10);
    }
}

int main() {
    int x, y; //natural numbers

    while (cin >> x >> y) {
        cout << "solutions for " << x << " and " << y << endl;

        bool solution = false; //we need it to know if there's a solution

        //Treats every base
        int base = 2;
        while (base <= 16) {
            if (same_digits(x, y, base)) {
                solution = true;

                //Prints the solution
                escriu(x, base);
                cout << ' ' << '*' << ' ';
                escriu(y, base);
                cout << ' ' << '=' << ' ';
                int aux = x * y;
                escriu(aux, base);

                cout << " (base " << base << ')' << endl;
            }

            ++base;
        }

        if (not solution) cout << "none of them" << endl;
        cout << endl;
    }
}
