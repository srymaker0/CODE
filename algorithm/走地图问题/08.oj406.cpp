/*************************************************************************
	> File Name: 8.oj406.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Sat 23 Jan 2021 01:37:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, sx, sy, ans;
char mmap[2005][2005];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, -1, 1, 1, 1, -1, -1, 1, -1};

void func(int x, int y) {
    mmap[x][y] = '.';
    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx > n - 1 || yy > m - 1) continue;
        if (mmap[xx][yy] == '#') {
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mmap[i][j] == '#') {
                ans++;
                func(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
