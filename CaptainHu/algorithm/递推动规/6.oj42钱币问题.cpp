/*************************************************************************
	> File Name: 6.oj42钱币问题.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 14 Feb 2021 04:05:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, v;
int f[25][10005];

int main() {
    cin >> m >> n;
    f[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> v;
        f[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v) f[i][j] += f[i][j - v];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
