/*************************************************************************
	> File Name: 1.lambda.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Mar 2021 06:49:51 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

function<int(int)> func(int x) {
    int n = 123;
    return [&](int k) -> int { return k * n + x; };
}

//lambda->简单的匿名函数
//lambda的捕获列表语法是独立的语法
int main() {
    //[]->捕获列表 ()->函数参数列表  {}->里面放逻辑代码
    //[]() {};  ->  一条语句
    auto test = func(3);
    cout << test(3) << endl;
    auto add = [](int a, int b) -> int { return a + b; };    //auto 推导的是lambda返回的类型，并不是函数指针类型
    auto add3 = [](int a, int b) -> int { return a + b; };   //每个lambda有一个自己的独立的类型
    function<int(int, int)> add2 = add;
    cout << add(3, 4) << endl;
    cout << typeid(add).name() << endl;
    cout << typeid(add2).name() << endl;
    cout << typeid(add3).name() << endl;
    /*
    int n = 12;
    auto times = [](int k) {   //不做任何处理 访问不到外部的任何变量
        return n * k;
    };
    */
    //捕获方式 值捕获， 引用捕获
    int n = 12;
    auto times = [=](int k) {   //一个=号是把外部的变量全都拷贝了一份
        return n * k;
    };
    cout << times(3) << endl;  //36, n = 12
    n = 14;
    cout << times(3) << endl;  //36, n = 12
    cout << "==================" << endl;
    auto times2 = [&n](int k) {
        return n * k;
    };
    cout << times2(3) << endl;  //42, n = 14
    n = 20;
    cout << times2(3) << endl;  //60, n = 20
    cout << test(3) << endl;
    return 0;
}
