#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    return fabs(a.first * (b.second	- c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) / 2;
}

int main() {
 	cout << "Ngo Dang Hanh" << endl;
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
