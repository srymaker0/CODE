/*************************************************************************
	> File Name: 22.oj382.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 18 Jan 2021 05:22:25 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    while (que.size() != 1) {
        for (int i = 1; i < m; i++) {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    } 
    cout << que.front() << endl;
    return 0;
}
