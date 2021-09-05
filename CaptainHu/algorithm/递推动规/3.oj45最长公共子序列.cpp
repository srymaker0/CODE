/*************************************************************************
	> File Name: 3.oj45最长公共子序列.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 03 Feb 2021 11:31:01 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000
string s1, s2;
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> s1 >> s2;
    for (int i = 1; s1[i - 1]; i++) {
        for (int j = 1; s2[j - 1]; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
