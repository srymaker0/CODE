/*************************************************************************
	> File Name: euler4.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Oct 2020 06:51:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int x) {
    int t = 0, raw = x;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    } 
    return t == raw;
}


int main() {
    int ans = 0;
    for (int i = 100 ; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (func(t)) {
                ans = max(ans,t);//max是c++内置的一个函数
            }
        }
    }
    cout << ans << endl;
    return 0;
}
