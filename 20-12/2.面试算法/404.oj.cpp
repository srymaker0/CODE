/*************************************************************************
	> File Name: 404.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 20 Nov 2020 01:08:30 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, mark[3003][3003], ans, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m || mark[xx][yy] == 1) {
            continue;
        }
        if (mmap[x][y] != mmap[xx][yy]) {
            ans++;
            mark[xx][yy] = 1;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    cin >> sx >> sy;
    ans = 1;
    mark[sx][sy] = 1;
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
