/*************************************************************************
	> File Name: 1.oj235.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Tue 19 Jan 2021 07:20:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans[15], cnt = 1;

void p() {
    for (int i = 1; i <= cnt; i++) {
        if (i != 1) cout << " ";
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
