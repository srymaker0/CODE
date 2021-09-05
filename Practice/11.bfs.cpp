/*************************************************************************
	> File Name: 11.bfs.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 10:46:09 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;
};
int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];
queue<node> que;


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
