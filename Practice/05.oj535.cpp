/*************************************************************************
	> File Name: 05.oj535.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 01:43:43 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, sx, sy, cnt = 1;
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {
            cnt++;
            mmap[xx][yy] = '#';
            func(xx, yy);
        }
    }
    return cnt;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    cout << func(sx, sy) << endl;
}
