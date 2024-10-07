//DISTANCE BETWEEN TWO POINTS

//Write a program that calculates the euclidean distance between two points a 
//and b.

//Input consist of two points a(x,y) and b(x,y).
//Output: prints the euclidean distance between both points.

#include <iostream>
#include <cmath>

using namespace std;

//Defines the coordinates of one point.
struct Point {
    double x, y;
};

//Reads the coordinates of a point.
//Pre: a point.
//Post: returns a.
void read_data(Point &a) {
    cin >> a.x >> a.y;
}

//Calculates the euclidean distance between two points, a and b.
//Pre: two points, a and b.
//Post: returns distance.
double dist(const Point& a, const Point& b) {
    double distance = sqrt((b.x - a.x) * (b.x - a.x) + 
                           (b.y - a.y) * (b.y - a.y));
    
    return distance;
}

int main() {
    Point a, b; 
    read_data(a);
    read_data(b);
    
    cout << dist(a, b) << endl; 
}
