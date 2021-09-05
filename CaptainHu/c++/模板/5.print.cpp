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

//模板类中的定义类型
template<typename T, typename ...ARGS>
struct N_ARGS {                              //定义一种结构
    typedef T type;                          //定义type表示第一个参数
    typedef N_ARGS<ARGS...> rest;            //rest除去第一个类型后剩下的类型 会递归展开
};

template<typename T>                        //偏特化，终止模板递归展开，只有一个参数
struct N_ARGS<T> {
    typedef T type;
    typedef T last;                         //可以确定最后一个类型是否真的是变参列表的最后一个类型 
};

template<typename T>
void print(T a){
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(T a, ARGS... args) {
    //输出一个参数后接着输出下一个参数的类型
    cout << a << " next type : " << typeid(typename N_ARGS<ARGS...>::type).name() << endl;
    print(args...);
    return ;
}

int main() {
    print(123, 45.6);
    print("hello", "world");
    print(123, "hello world", "haizei", 45.6);
    N_ARGS<int, int, double, double>::type x;                     //模板类中的第一个类型
    N_ARGS<int, int, double, double>::rest::type y;               //模板类中除去第一个类型剩余类型中的第一个类型
    N_ARGS<int, int, double, double>::rest::rest::type z;
    N_ARGS<int, int, double, double>::rest::rest::rest::last w;   //last表示最后一个类型
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    cout << typeid(w).name() << endl;
    return 0;
}
