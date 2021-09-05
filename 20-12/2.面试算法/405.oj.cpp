/*************************************************************************
	> File Name: 405.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 20 Nov 2020 02:18:32 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

queue<node> que;
int n, m, k, ans[3005][3005], temp;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];

void check() {
    while (!que.empty()) {
        node t = que.front();
        que.pop();
        ans[t.x][t.y] = temp;
    }
}

void func(int x, int y) {
    que.push((node){x, y});
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m || ans[xx][yy] != 0) {
            continue;
        }
        if (mmap[x][y] != mmap[xx][yy]) {
            ans[xx][yy] = 1;
            temp++;
            func(xx,yy);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == 0) {
                temp = 1;
                ans[i][j] = 1;
                func(i, j);
                check();
            }
        }
    }
}

