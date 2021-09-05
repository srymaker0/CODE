/*************************************************************************
	> File Name: 5.printf.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 14 Mar 2021 03:34:29 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


//模板的偏特化，结束递归，只有一个参数
template<typename T>
void print(T a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>      //typename ...表示变参部分， ARGS表示一组变参类型
void print(T a, ARGS... args) {             //a是第一个参数， 后面是变参部分
    cout << a << endl;
    print(args...);                         //递归调用 要有递归终止条件， 这里用到了模板片偏特化    
    return ;
}

int main() {
    print(123);
    print(123, "hello world", "haizei", 45.6);
    return 0;
}
