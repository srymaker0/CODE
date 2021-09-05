/*************************************************************************
	> File Name: 17.oj402.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 09:39:41 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int now, step;
};

int n, a, b, num[205], check[205];

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    queue<node> que;
    que.push((node){a, 0});
    check[a] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.now == b) {
            cout << temp.step << endl;
            return 0;
        }
        int up = temp.now + num[temp.now];
        int down = temp.now - num[temp.now];
        if (up <= n && check[up] == 0) {
            check[up] = 1;
            que.push((node){up, temp.step + 1});
        }
        if (down > 0 && check[down] == 0) {
            check[down] = 1;
            que.push((node){down, temp.step + 1});
        }
    }
    cout << -1 << endl;
    return 0;
}
