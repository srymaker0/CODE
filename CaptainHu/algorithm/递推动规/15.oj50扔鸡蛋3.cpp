/*************************************************************************
	> File Name: 15.oj50扔鸡蛋3.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 16 Feb 2021 03:36:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 32
#define MAX_X 50000
long long dp[2][MAX_X + 5];

int solve(int n, int m) {
    if (n == 1) return m;
    for (int i = 1; i <= MAX_X; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= MAX_X; j++) {
            dp[i % 2][j] = dp[i % 2][j - 1] + dp[(i - 1) % 2][j - 1] + 1;
        }
    }
    int k = 1;
    while (dp[n % 2][k] < m) k++;
    return k;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;

    return 0;
}
