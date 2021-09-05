/*************************************************************************
	> File Name: 06.RVO.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 06:39:18 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() {
        cout << this <<"default constructor" << endl;
    }
    A(int x) : x(x) {
        cout << this <<"transform constructor" << endl;
    }
    A(const A &a) {
        cout << this <<"copy constructor" << endl;
    }
    int x;
};

A func() {
    A temp(69);
    cout << "&temp : " << &temp << endl;
    return temp;
}

int main() {
    A a = func();
    cout << "&a : " << &a << endl;
    cout << a.x << endl;
    return 0;
}
