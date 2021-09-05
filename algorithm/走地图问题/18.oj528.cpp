/*************************************************************************
	> File Name: 18.oj528.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 09:57:50 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int now, step;
};

int n, x, y, arr[105][105], check[105];

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
        if (temp.now == y) {
            cout << temp.step - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (arr[temp.now][i] == 1 && check[i] == 0) {
                check[i] = 1;
                que.push((node){i, temp.step + 1});
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
