/*************************************************************************
	> File Name: 236.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 18 Nov 2020 03:02:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, num[15], cnt; //cnt 体现回溯感

void p() {
    for (int i = 0; i < cnt; i++) {
        if (i) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

//s: 从几开始选  left: 还要选几个数
void func(int s, int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = s; i <= n; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
