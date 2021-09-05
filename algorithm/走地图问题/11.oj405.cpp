/*************************************************************************
	> File Name: 11.oj405.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 03:00:07 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

int n, m, k, ans[3005][3005], cnt;
char mmap[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

void save() {
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        ans[temp.x][temp.y] = cnt;
    }
}

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m || ans[xx][yy] != 0) {
            continue;
        }
        if (mmap[x][y] != mmap[xx][yy]) {
            cnt++;
            ans[xx][yy] = 1;
            que.push((node){xx, yy});
            func(xx, yy);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == 0) {
                cnt = 1;
                que.push((node){i, j});
                ans[i][j] = 1;
                func(i, j);
                save();
            }
        } 
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[a][b]);
    }

    return 0;
}
