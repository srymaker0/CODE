/*************************************************************************
	> File Name: 81.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 20 Nov 2020 06:23:12 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step, f;//f 去没去过手机店 
};

int n, m, check[2005][2005];
char mmap[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                que.push((node){i, j, 0, 0});
                check[i][j] = 1;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if ((check[x][y] & 1) && temp.f == 0) {
                continue;
            }
            if ((check[x][y] & 2) && temp.f == 1) {
                continue;
            }
            if (mmap[x][y] == 'T' && temp.f == 1) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.' || mmap[x][y] == 'S' || mmap[x][y] == 'T') {
                que.push((node){x, y, temp.step + 1, temp.f});
                check[x][y] += temp.f + 1;
            }
            if (mmap[x][y] == 'P') {
                que.push((node){x, y, temp.step + 1, 1});
                check[x][y] = 3;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
