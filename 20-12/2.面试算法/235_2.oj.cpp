/*************************************************************************
	> File Name: 235_2.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 18 Nov 2020 02:55:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[15], cnt;

void p() {
    for (int i = 0; i <= cnt; i++) {
        if (i) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt] = i;
        p();
        cnt++;
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
