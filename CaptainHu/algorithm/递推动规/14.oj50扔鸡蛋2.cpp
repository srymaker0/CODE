/*************************************************************************
	> File Name: 14.oj50扔鸡蛋.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 15 Feb 2021 06:09:48 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 32
#define MAX_M 1000000
int dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        int k = 1;
        for (int j = 1; j <= m; j++) {
            if (dp[i - 1][k] <= dp[i][j - k - 1]) ++k;
            dp[i][j] = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
