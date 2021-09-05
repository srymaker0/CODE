/*************************************************************************
	> File Name: 03.constructor.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 02:33:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public :
    Data(int x, int y) : x(x), y(y) {}                      
private :
    int x, y;
};

class A {
public :
    A() : d(3, 4) {
        cout << this << " : constructor" << endl;          // this 是 对象的地址
    }
    A(int x) : d(x, x) {                                            //转化构造函数  这里是把一个整型转换成A类型的对象 
        cout << this << " : transform constructor" << endl;
    }
    A(const A &a) : d(a.d) {                                       // &a 是引用 const为了防止a对象被修改 const变量不允许被修改
        cout << this << " : copy constructor" << endl;
    }
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;
        return *this;
    }
    ~A() {
        cout << this << " : destructor" << endl;          //在主函数运行结束后被调用
    }
    Data d;
};

//关键在于学习对象析构顺序 先构造的后析构
int main() {
    A a;                             //构造对象 调用默认构造函数
    A b = a;                         //调用拷贝构造 和 A b(a); 一样
    //b = a;                         //调用赋值运算符 
    A c = 3;
    a = 123; 
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    cout << "end of main" << endl;
    return 0;
}
