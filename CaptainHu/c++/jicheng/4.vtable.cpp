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
    A() { this->x = 200; this->y = 400;  }
    virtual void say(int x) {
        cout << "Class A say :" << x << endl;
    }
    virtual void run() {
        cout << "Class A run :" << endl;
    }
    void reg1() {
        cout << "reg1 function " << endl;
    }
    void reg2() {
        cout << "reg2 function " << endl;
    }
    void reg3() {
        cout << "reg3 function " << endl;
    }
    int x;
    int y;
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

void func1() {}

//函数指针，我要指向虚函数表里存放的函数
typedef void (*func)(void *, int);    //say()方法中只有1个参数，这里为什么要传两个呢？
                                      //在所有的成员方法的底层实现中会有一个this指针的参数
                                //但是在类中却隐藏掉了(被编译器修饰过了)，所以这里的第一个参数是this指向的对象的地址
int main() {
    A a;
    B b;
    C c;
    TEST(a);
    TEST(b);
    TEST(c);
    
    //使b的虚函数表的地址指向c的， 对象的前8个字节存储的是虚函数表的地址
    //取b的首地址中存放虚函数表的地址 
    ((void **)(&b))[0] = ((void **)(&c))[0];   //证明存在虚函数表
    TEST(b);
    
    //证明虚函数表里存在虚函数
    ((func **)(&b))[0][0](&b, 123);   //取b的首地址中存放虚函数表的地址指向的第一个函数 
    //普通的函数指针没有this指针这个概念 所以下面这段代码会报错
    //void (*p = &A::say)(); //报错
    
    //成员方法指针才能存储普通成员函数
    //定义函数指针 p(A *, ...) 
    void (A::*p)(int);       //表示A类中的成员方法指针
    p = &A::say;             //指向say()方法      
    (a.*p)(12345);           //使用函数指针调用say()
   
    //随机调用reg()成员函数
    void (A::*k[3])();    //成员方法指针数组
    k[0] = &A::reg1;
    k[1] = &A::reg2;
    k[2] = &A::reg3;
    for (int i = 0; i < 10; i++) {
        (a.*k[rand() % 3])();
    }

    int A::*q;               //成员属性指针  
    q = &A::x;               //指向A类型中的x属性
    cout << (a.*q) << endl;  //*q == x 
    q = &A::y;
    cout << (a.*q) << endl;
    //成员函数指针和成员属性指针都是字段等价替换功能

    return 0;
}
