/*************************************************************************
	> File Name: 11.oj48完全背包.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 14 Feb 2021 09:42:54 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000
int dp[MAX_N + 5];

int main() {
    int V, n, v, w;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}

