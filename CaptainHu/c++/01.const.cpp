/*************************************************************************
	> File Name: 1.const.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 02 Mar 2021 01:41:46 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() { x = 123; y = 0; }
    void say1() const {        //const可以修饰成员方法 代表这个方法内部不能修改成员属性
        cout << y << endl;
                       y += 1;                 //y用来记录say1方法被调用几次 逻辑上的const
    }
    void say2() {
        x = 456;
    }
    int x;
    mutable int y;             //y是一种用户不可知的需求 对于对象而言可以改变 不影响用户使用
};

int main() {
    //const int a = 1;          //对于编译器来说 a是数据意义上的const 因为编译器不让我们改 
    const A a;                  //const类性的对象 此对象里的任何内容都不可修改
    a.say1();                   //const类型的方法可以通过编译
    //a.say2();                   //非const类型表示可能a的成员属性会被修改 但是a是一个const类型
    return 0;
}
