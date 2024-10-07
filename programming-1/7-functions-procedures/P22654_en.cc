//TIME DECOMPOSITION (2)

//Write a procedure void decompose(int n, int& h, int& m, int& s) that, given 
//a quantity of seconds n, computes how many hours h, minutes m and seconds s 
//it represents. 

//Input consists of a natural number.
//Output: prints a time in hours, minutes and seconds.

#include <iostream>

using namespace std;

//Decomposes n and stores the decomposition in h, m and s.
//Pre: n is a natual number.
//Post: returns h, m, s.
void decompose(int n, int &h, int &m, int &s){
    h = n / 3600;
    m = ((n % 3600) / 60) % 60;
    s = ((n % 3600) % 60) % 60;
}

int main() {
    int num, hours, min, sec;
    
    while (cin >> num) {
        decompose(num, hours, min, sec);
        
        cout << hours << ' ' << min << ' ' << sec << endl;
    }
}
