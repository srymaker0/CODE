/*************************************************************************
	> File Name: 379.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Thu 26 Nov 2020 02:59:51 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack<int> g, mmax;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, num;
        cin >> t;
        if (t == 0) {
            cin >> num;
            g.push(num);
            if (mmax.empty()) {
                mmax.push(num);
            } else {
                mmax.push(max(num, mmax.top()));
            }
        } else if (t == 1) {
            if (!g.empty()) {
                g.pop();
                mmax.pop();
            }
        } else if (t == 2) {
            if (g.empty()) {
                cout << 0 << endl;
            } else {
                cout << mmax.top() << endl;
            }
        }
        
    } 
    return 0;
}
