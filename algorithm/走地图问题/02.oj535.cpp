/*************************************************************************
	> File Name: 2.oj535.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Thu 21 Jan 2021 06:53:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, sx, sy, ans = 1;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[55][55];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {
            ans++;
            mmap[xx][yy] = '#';
            func(xx, yy);
        }
    }
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
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
