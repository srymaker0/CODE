/*************************************************************************
	> File Name: 528.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 20 Nov 2020 06:53:48 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int now, step;
};

int n, x, y, check[105], arr[105][105];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    queue<node> que;
    que.push((node){x, 0});
    check[x] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 1; i <= n; i++) {
            if (arr[temp.now][i] == 1 && check[i] == 0) {
                if (i == y) {
                    cout << temp.step << endl;
                    return 0;
                }
                que.push((node){i, temp.step + 1});
                check[i] = 1;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
