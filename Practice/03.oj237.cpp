/*************************************************************************
	> File Name: 3.oj237.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 01:23:18 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans[15], mark[15];

void p() {
    for (int i = 1; i <= n; i++) {
        i != 1 && cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

void func(int cnt) {
    if (cnt == n + 1) {
        p();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            ans[cnt] = i;
            func(cnt + 1);
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
