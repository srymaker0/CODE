/*************************************************************************
	> File Name: 2.bind.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 20 Mar 2021 08:14:24 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void func(int x) {
    cout << x << endl;
    return ;
}

void add(int a, int b) {
    cout << a << " + " << b << endl;
    return ;
}

void test_ref(int &x) {
    x += 1;
    cout << "test_ref function" << endl;
    return ;
}

int main() {
    func(123);
    function<void()> f = bind(func, 123);
    cout << "==========" << endl;
    f();
    function<void(int)> add3 = bind(add, 3, std::placeholders::_1);     //单独的参数绑定
    add3(45);    //3 + 45
    add3(89);    //3 + 89
    add3(100);
    //placeholders 占位符， a给了2号槽位， b给了1号槽位 灵活的控制参数顺序和参数个数
    function<void(int, int)> add2 = bind(add, std::placeholders::_2, std::placeholders::_1);
    add2(3, 4);
    int n = 0;
    function<void()> ref_func = bind(test_ref, ref(n));    //bind默认绑定值，要绑定引用必须要显示调用ref
    cout << n << endl;
    ref_func();
    cout << n << endl;
    
    auto weird_func = bind(add, placeholders::_4, placeholders::_1);
    weird_func(1, 2, 3, 4);
    return 0;
}
