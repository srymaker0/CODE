/*************************************************************************
	> File Name: 379.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 07:01:41 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;


int main() {
    int n;
    stack<int> g, mmax; // g 货物栈 mmax 极大值栈
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            cin >> t;
            g.push(t);
            if (mmax.empty()) {
                mmax.push(t);
            } else {
                mmax.push(max(t, mmax.top()));    
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
