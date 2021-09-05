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
    A() : x(123), y(0) { x = 123; y = 0; }
    void say1() const {        
        cout << y << endl;
        y += 1;                
    }
    void say2() {
        x = 456;
    }
    int x;
    mutable int y;             
};

int main() {
    //const int a = 1;          
    const A a;                 
    a.say1();                   //const类型的方法可以通过编译
    //a.say2();                   //非const类型表示可能a的成员属性会被修改 但是a是一个const类型
    return 0;
}
