/*************************************************************************
	> File Name: 12.oj404.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 03:21:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, a, b, cnt;
char mmap[3005][3005];
char check[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
        if (mmap[xx][yy] != mmap[x][y] && check[xx][yy] == 0) {
            cnt++;
            check[xx][yy] = 1;
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
    cin >> a >> b;
    cnt = 1;
    check[a][b] = 1;
    func(a, b);
    cout << cnt << endl;
    return 0;
}
