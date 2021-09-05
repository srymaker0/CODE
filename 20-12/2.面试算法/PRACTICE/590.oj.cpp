/*************************************************************************
	> File Name: 590.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 2020 02:41:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//num 原始的数   ans 经过每个点能获得的最大值 mmax[x][0] 最大值的坐标 mmax[x][1] 次大值
int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005][2];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {
        for (j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int m2 = 0, m1 = 0, cnt = 0;//m2 次大值 m1最大值 cnt最大值的坐标
        for (int j = 1; j <= i; j++) {
            if (ans[i][j] > m1) {
                m2 = m1;
                m1 = ans[i][j];
                cnt = j;
            } else if(m2 < ans[i][j]) {
                m2 = ams[i][j];
            }
        }
        mmax[i][0] = cnt;
        mmax[i][1] = m2;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1\n");
        } else if (mmax[a][0] == b) {
            printf("%d\n", mmax[a][1]);
        } else {
            printf("%d\n", dtu[1][1]);
        }
    }

    return 0;
}
