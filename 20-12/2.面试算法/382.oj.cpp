/*************************************************************************
	> File Name: 382.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 07:25:57 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, now = 1;
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        que.push(1);
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
