/*************************************************************************
	> File Name: 5.print.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

template<typename T, typename ...ARGS>
struct N_ARGS {
    typedef T type;
    typedef N_ARGS<ARGS...> rest;
};

template<typename T>
struct N_ARGS<T> {
    typedef T type;
    typedef T last;
};

// 优化版：第一位放入数字，代表我们希望定位到变参列表的第几个参数
template<int N, typename T, typename ...ARGS>
struct New_N_ARGS {
    typedef typename New_N_ARGS<N - 1, ARGS...>::type type;
    static int last() {                                      //定义成类方法
        return New_N_ARGS<N - 1, ARGS...>::last();           //回溯中若返回1，则是最后一个参数，用于判断最后一个参数
    }
};

// 第一种情况
// 偏特化，取第1个参数类型并且后面还有参数
template<typename T, typename ...ARGS>
struct New_N_ARGS<1, T, ARGS...> {
    typedef T type;                  
    static int last() { return 0; }
};

// 第二种情况
// 没有变参列表，说明是最后一个参数类型
template<typename T>
struct New_N_ARGS<1, T> {
    typedef T type;
    static int last() { return 1; }
};

template<typename T>
void print(T a){
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(T a, ARGS... args) {
    cout << a << " next type : " << typeid(typename N_ARGS<ARGS...>::type).name() << endl;
    print(args...);
    return ;
}

//测试宏，func...变参 宏区分参数是用逗号来区分的，所以要传变参
#define Test(func...) cout << #func << " = " << func << endl

int main() {
    print(123, 45.6);
    print("hello", "world");
    print(123, "hello world", "haizei", 45.6);
    N_ARGS<int, int, double, double>::type x;
    N_ARGS<int, int, double, double>::rest::type y;
    N_ARGS<int, int, double, double>::rest::rest::type z;
    N_ARGS<int, int, double, double>::rest::rest::rest::last w;
    New_N_ARGS<1, int, int, double, double>::type x1;
    New_N_ARGS<2, int, int, double, double>::type y1;
    New_N_ARGS<3, int, int, double, double>::type z1;
    New_N_ARGS<4, int, int, double, double>::type w1;
    
    Test(New_N_ARGS<1, int, int, double, double>::last());
    Test(New_N_ARGS<2, int, int, double, double>::last());
    Test(New_N_ARGS<3, int, int, double, double>::last());
    Test(New_N_ARGS<4, int, int, double, double>::last());
    
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    cout << typeid(w).name() << endl;
    cout << typeid(x1).name() << endl;
    cout << typeid(y1).name() << endl;
    cout << typeid(z1).name() << endl;
    cout << typeid(w1).name() << endl;
    return 0;
}
