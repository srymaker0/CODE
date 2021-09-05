/*************************************************************************
	> File Name: 383.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 25 Nov 2020 08:44:12 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    queue<int> que1,que2;
    for (int i = 1; i <= n; i++) {
        que1.push(i);
    }
    for (int i = 1; i <= m; i++) {
        que2.push(i);
    }
    for (int j = 0; j < x; j++) {
        cout << que1.front() << " " << que2.front() << endl;
        que1.push(que1.front());
        que2.push(que2.front());
        que1.pop();
        que2.pop();
    }

    return 0;
}
