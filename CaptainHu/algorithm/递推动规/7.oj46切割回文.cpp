/*************************************************************************
	> File Name: 7.oj46切割回文.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 14 Feb 2021 04:38:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 500000
int dp[MAX_N + 5];

bool is_palindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i++] - s[j--]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    dp[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            if(is_palindrome(s, j, i - 1)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[s.size()] - 1 << endl;
    return 0;
}
