/*************************************************************************
	> File Name: 07.oj563.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 08:05:11 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, sum, ans;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '1') {
            ans++;
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '1') {
                ans = 1;
                mmap[i][j] = 0;
                func(i, j);
                sum = max(sum, ans);
            }
        }
    }
    cout << sum << endl;
    return 0;
}
