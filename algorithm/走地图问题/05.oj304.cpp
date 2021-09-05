/*************************************************************************
	> File Name: 5.oj304.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Thu 21 Jan 2021 08:16:03 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, sx, sy;
char mmap[200][200];

int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
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
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[xx][yy] == '.') {
                que.push((node){xx, yy, temp.step + 1});
                mmap[xx][yy] = 0;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}
