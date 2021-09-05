/*************************************************************************
	> File Name: 5.bind_order.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 07:57:07 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
/*
void func1(int &x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}
*/
void func1(const int &x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}
/*
void func1(int &&x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}
*/
/*
void func1(const int &&x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;   
}
*/
int main() {
    int n;
    const int y = 123;
    func1(n);             //func1(int &x)
    func1(y);             //func1(const int &x)
    func1(123 + 456);     //func1(int &&)
    return 0;
}
