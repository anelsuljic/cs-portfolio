//MOVEMENTS ON THE GROUND

//The program reads a sequence of characters that codifies a movement, and
//computes the final position of an object located initially at (0, 0).

//Input consists of a sequence of characters ‘n’, ‘s’, ‘e’, or ‘w’.
//Output: Print the final position of an object initially located at (0, 0).

#include <iostream>

using namespace std;

int main() {
    char location; //'n','s','e','w'.

    int north_south = 0;
    int east_west = 0;

    while (cin >> location) {
        if (location == 'n') --north_south;
        else if (location == 's') ++north_south;
        else if (location == 'e') ++east_west;
        else --east_west;
    }

    cout << '(' << east_west << ',' << ' ' << north_south << ')' << endl;
}
