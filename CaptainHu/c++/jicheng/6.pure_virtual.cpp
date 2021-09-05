/*************************************************************************
	> File Name: 4.vtable.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 07 Mar 2021 03:27:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() { this->x = 200; }
    virtual void say(int x) {
        cout << "Class A say :" << x << endl;
    }
    virtual void run() {
        cout << "Class A run :" << endl;
    }
    int x;
};

class B : public A {
public :
    B() { x = 300; }
    void say(int x) override {
        cout << "Class B say" << x << endl;
    }
};

class C : public A {
public :
    C() { x = 400; }
    void run() override {
        cout << "Class C run" << endl;
    }
};

#define TEST(a) test(a, #a)
void test(A &a, string class_name) {
    cout << "Object " << class_name << endl;
    a.say(123);
    a.run();
    cout << "====================" << endl << endl;
    return ;
}

typedef void (*func)(void *, int);

int main() {
    A a;
    B b;
    C c;
    TEST(a);
    TEST(b);
    TEST(c);
    ((void **)(&b))[0] = ((void **)(&c))[0];
    TEST(b);
    ((func **)(&b))[0][0](&b, 123);
    void (A::*p)(int);
    p = &A::say;
    (a.*p)(12345);
    
    return 0;
}
