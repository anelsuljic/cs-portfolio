//PREFIXED EXPRESSION

//Write a program that reads a prefixed expression, and prints the result of
//evaluating it. The three possible operators are sum, substraction and
//multiplication. The operands are natural numbers between 0 and 9 (both
//included).

//Input has a prefixed expression. This means that operators always appear
//before their operands.
//Output: Print a line with an integer number: the result of evaluating the
//given expression.

#include <iostream>

using namespace std;

//Reads a prefixed expression and calculates the result of that expression.
//Pre: ----------
//Post: returns result.
int expression() {
    char elem;
    cin >> elem;

    int result = 0;

    //Base case
    if (elem >= '0' and elem <= '9') result = elem - '0';

    //Recursive condition
    else {
        if (elem == '+') {
            result = expression() + expression();
        }
        else if (elem == '-') {
            result = expression() - expression();
        }
        else if (elem == '*') {
            result = expression() * expression();
        }
    }

    return result;
}

int main() {
    cout << expression() << endl;
}
