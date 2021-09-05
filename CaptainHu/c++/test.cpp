/*************************************************************************
	> File Name: test.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 08 Mar 2021 09:08:56 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public :
    Point();
    Point(int x, int y);
    //类内重载
    Point operator+(const Point &a);
    Point &operator+=(int);
    int operator[](string s);
    int getX() { return x; }
    int getY() { return y; }
private :
    friend ostream &operator<<(ostream &out, const Point &d);
    friend Point operator+(const Point &a, const Point &b);
    int x, y;
};

class PPoint {
public :
    PPoint(Point *p) : p(p) {}   //传的是地址
    Point *operator->() { return p; }       //返回的是指针类型
private :
    Point *p;
};


class ADD {
public :
    ADD(int c) : c(c) {}
    int operator()(int a, int b) {
        return a + b + c;
    }
private :
    int c;
};

//委托构造，此时默认构造函数会调用有参构造进行初始化
Point::Point() : Point(0, 0) {}
Point::Point(int x, int y) : x(x), y(y) {}

int Point::operator[](string s) {
    if (s == "x") return x;
    if (s == "y") return y;
    return 0;
}

Point &Point::operator+=(int n) {
    x += n, y += n;
    return *this;
}

//类外重载
Point operator+(const Point &a, const Point &b) {
    cout << "outer operator+" << endl;
    Point c(a.x + b.x, a.y + b.y);
    return c;
}

//类内
Point Point::operator+(const Point &a) {
    cout << "inner operator+" << endl;
    Point c(x + a.x, y + a.y);
    return c;
}

ostream &operator<<(ostream &out, const Point &a) {
    out << a.x << " " << a.y;
    return out;
}

int main() {
    ADD add(5);
    cout << add(6, 7) << endl;
    Point a(3, 4);
    Point b(7, 9);
    cout << a["x"] << endl;  //a对象的外在表现像一个数组，但是本质是一个对象 
    cout << a["y"] << endl;
    Point c = a + b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    a += 2;
    cout << a << endl;
    PPoint p = &a;
    cout << p->getX() << " " << p->getY() << endl;
    return 0;
}
