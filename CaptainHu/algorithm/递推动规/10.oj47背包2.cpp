/*************************************************************************
	> File Name: 10.oj47背包2.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 14 Feb 2021 07:50:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 10000
int dp[MAX_V + 5];

int main() {
    int V, n, v, w;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
