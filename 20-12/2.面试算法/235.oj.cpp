/*************************************************************************
	> File Name: 235.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 18 Nov 2020 02:36:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[15];

void p(int deep) {
    for (int i = 1; i <= deep; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int s, int deep) {
    for (int i = s; i <= n; i++) {
        num[deep] = i;
        p(deep);
        func(i + 1, deep + 1);
    }
}

int main() {
    cin >> n;
    func(1, 1);//第一个参数:这一层从几开始选 第二个参数:这一层是第几层
    return 0;
}
