/*************************************************************************
	> File Name: 15.oj81.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 07:37:57 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step, f;
};

int n, m, check[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[2005][2005];

int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
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
            if (mmap[x][y] == 'T' && temp.f == 1) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if ((check[x][y] & 1) && temp.f == 0 || (check[x][y] & 2) && temp.f == 1) {
                continue;
            }
            if (mmap[x][y] == '.' || mmap[x][y] == 'S' || mmap[x][y] == 'T') {
                check[x][y] += temp.f + 1;
                que.push((node){x, y, temp.step + 1, temp.f});
            }
            if (mmap[x][y] == 'P') {
                check[x][y] = 3;
                que.push((node){x, y, temp.step + 1, 1});
            }
        }
    }
    return 0;
}
