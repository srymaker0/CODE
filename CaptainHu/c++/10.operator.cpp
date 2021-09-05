/*************************************************************************
	> File Name: 10.operator.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 06 Mar 2021 02:38:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public :
    Point() : x(x), y(y) {}
private :
    friend ostream &operator<<(ostream &, const Point &); 
    int x, y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

int main() {
    Point a(3, 4);
    cout << a << endl;
    return 0;
}
