/*************************************************************************
	> File Name: 2.constexpr.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 02:57:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//编译期常量-constexpr  必须在编译期确定 编译期可以初始化的常量表达式对象
//运行期常量-const
//取地址是一个运行期的功能， 不会在编译期被优化

constexpr int f(int x) {    
    return 2 * x;
}

class A {
public :
    constexpr A (int x) {}    //说明是编译期常量方法
}; 

int main() {
    int n;
    cin >> n;
    const int x = n + 123;
    //constexpr int y = n + 123;      //由于n在运行期才能确定，而constexpr在编译期就要确定常量值，报错
    constexpr int y1 = 123;
    constexpr int y2 = f(123);        //f类型若不加constexpr修饰，会报错，无法在编译期确定  
    const A a(123);
    constexpr A b(123);               //构造函数在运行期
    
    
    /*
    const int x = 123;
    constexpr int y = 123;
    *const_cast<int *>(&x) = 456;
    *const_cast<int *>(&y) = 456;
    cout << &x << endl;
    cout << *(&x) << endl;
    //x = 456;
    //y = 456;
    */
    return 0;
}
