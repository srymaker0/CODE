/*************************************************************************
	> File Name: barber.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 25 Nov 2020 02:54:39 PM CST
 ************************************************************************/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, m, status;



int main() {
    cin >> n >> m;
    stack<int> sta;
    queue<int> que, ctm;
    for (int i = 1; i <= n; i++) {
        ctm.push(i);
    }
    while (ctm.empty()) {
        if (sta.size() == 0) {
            cout << "sleep" << endl;
            sta.push(ctm.front());
        }
        ctm.pop();
        sta.push(ctm.front());
        if (sta.size() > 1) {
            cout << "cutting" << endl;
            que.push(sta.top());
            sta.pop();
            
        }
        break;
    }

    return 0;
}
