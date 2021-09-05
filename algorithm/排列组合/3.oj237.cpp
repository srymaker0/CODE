/*************************************************************************
	> File Name: 3.oj237.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Tue 19 Jan 2021 08:22:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans[15], mark[15];

void p() {
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
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
            ans[cnt] = i;
            mark[i] = 1;
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
