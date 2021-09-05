/*************************************************************************
	> File Name: 9.e15.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Dec 2020 07:28:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long dp[25][25];

int main() {
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[21][21] << endl;
    return 0;
}
