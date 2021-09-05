/*************************************************************************
	> File Name: 600.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 27 Nov 2020 10:16:24 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, t, num[3005][3005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    scanf("%d", &t);
    int x = n, y = 1;
    while (1) {
        if (num[x][y] == t) {
            printf("%d %d", x, y);
            return 0;
        }
        if (num[x][y] > t) x--;
        else y++;
        if (x < 1 || y > m) break;
    }
    printf("-1\n");
    return 0;
}
