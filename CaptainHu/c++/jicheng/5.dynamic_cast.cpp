/*************************************************************************
	> File Name: 5.dynamic_cast.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 07 Mar 2021 04:37:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() {
        cout << "A constructor" << endl;
    }
    /*
    virtual void say() {
        cout << "Class A" << endl;
    }
    */
    //具有继承关系的类必须要有虚函数，否则将无法正确析构。
    virtual ~A() {
        cout << "A destructor" << endl;
    }
};

class B : public A {
public :
    B() {
        cout << "B constructor" << endl;
    }
    /*
    virtual void say() override {
        cout << "Class B" << endl;
    }
    */
    virtual ~B() {
        cout << "B destructor" << endl;
    }
};

class C : public A {
public :
    C() {
        cout << "C constructor" << endl;
    }
    /*
    virtual void say() override {
        cout << "Class C" << endl;
    }
    */
    virtual ~C() {
        cout << "C destructor" << endl;
    }
};

void judge(A *p) {

}

int main() {
    srand(time(0));
    A *p;
    switch (rand() % 2) {
        case 0: p = new B(); break;
        case 1: p = new C(); break;
    }
    //代码到这里p指向的是B还是C 我们是不确定的
    //传入一个地址p， 再把p转换成<>里的(目标地址)B类型的地址
    //如果p真的指向目标地址，则转换成功， 否则会返回空地址
    cout << dynamic_cast<B *>(p) << endl;
    cout << dynamic_cast<C *>(p) << endl;
    delete p;
    return 0;
}
