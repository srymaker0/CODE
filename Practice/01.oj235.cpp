/*************************************************************************
	> File Name: 1.oj235.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 11:49:41 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans[15], cnt = 1;

void p() {
    for (int i = 1; i <= cnt; i++) {
        i != 1 && cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        ans[cnt] = i;
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
