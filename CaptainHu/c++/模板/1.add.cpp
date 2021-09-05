/*************************************************************************
> File Name: 1.add.cpp
> Author: ZYJ 
> Mail: NO
> Created Time: Sat 13 Mar 2021 08:24:34 PM CST
************************************************************************/

#include <iostream>
using namespace std;


//一
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}


//二 模板的偏特化，传入参数是指针时，会调用这版的
template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return *a + *b;
}

//三 模板的特化
template<>
int add(int a, int b) {
    return a + 2 * b;
}

auto func(int a, int b) ->int {
    return a + b;
}

int main() {
    //模板偏特化
    int n = 123, m = 456;
    int *p = &n, *q = &m;
    cout << add(p, q) << endl;  //调用二的
    return 0;
}
