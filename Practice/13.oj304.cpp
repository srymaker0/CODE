/*************************************************************************
	> File Name: 13.oj304.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 11:23:18 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};
int n, m, sx, sy;
int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
char mmap[200][200];

int main() {
    cin >> m >> n;
    for (int i = 5; i < n + 5; i++) {
        for (int j = 5; j < m + 5; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                sx = i;
                sy = j;
            }
        }
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                que.push((node){x, y, temp.step + 1});
                mmap[x][y] = '#';
            }
        }
    }
    return 0;
}
