/*************************************************************************
	> File Name: 382.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Thu 26 Nov 2020 03:37:46 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, now = 1;
    queue<int> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    while (que.size() != 1) {
        if (now == m) {
            que.pop();
            now = 1;
        } else {
            que.push(que.front());
            now++;
            que.pop();
        }
    }
    cout << que.front() << endl;
    return 0;
}
