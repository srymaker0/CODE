/*************************************************************************
	> File Name: 1.auto.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 02:11:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;


//auto 不能作为函数参数   不能作为模板参数   不能定义数组  不能用于非静态成员变量

int main() {
    int x;
    auto y = 12.3;  //auto自动推导x的类型  不是c++11新引入的  c语言中就有
    int z = 123;
    cout << typeid(y).name() << endl;       //typeid返回 类型信息对象  
    if (typeid(y).hash_code() == typeid(float).hash_code()) {
        cout << "float type" << endl;
    }
    if (typeid(y).hash_code() == typeid(double).hash_code()) {
        cout << "double type" << endl;
    }
    //cout << typeid(x).raw_name() << endl; 
    //auto int z = 123;    //局部的自动变量 其实就是局部变量  在c语言中多余
    map<int, int> arr;   //容器：装数据的地方，封装好的数据结构set，map，vector都是容器
    for (int i = 0; i < 10; i++) {
        arr[rand() % 100] = rand();
    }

    //遍历容器中的相关元素  stl提供的方式 迭代器类型 每一种容器的迭代器类型都是不一样的
    //auto编译期就可以确定这个变量的类型
    //map<int, int>::inerator 这是一个类型 后面可以跟变量
    //map<int, int>::iterator iter = arr.begin();    太长了可以用auto   
    auto iter = arr.begin();   //返回值由arr.begin()的返回值类型决定->map
    while (iter != arr.end()) {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
    for (auto x : arr) {    //for循环的特殊形式
        cout << x.first << " " << x.second << endl;
    }
    cout << sizeof(x) << endl;   //占据整型存储空间
    cout << sizeof(y) << endl;   //占据double存储空间
    return 0;
}
