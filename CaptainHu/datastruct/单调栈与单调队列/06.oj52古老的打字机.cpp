/*************************************************************************
	> File Name: 06.oj52古老的打字机.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 17 Feb 2021 10:57:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000
#define S(a) ((a) * (a))
long long s[MAX_N + 5], f[MAX_N + 5], dp[MAX_N + 5];
int n, M;
int q[MAX_N + 5], head, tail;

double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (s[i] - s[j]);
}

void read() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    return ;
}

void set_dp(int i, int j) {
    dp[i] = dp[j] + S(s[i] - s[j]) + M;
    f[i] = dp[i] + S(s[i]);
    return ;
}

long long solve() {
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head], q[head + 1]) < 2 * s[i]) ++head;
        set_dp(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 1], i) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }
    return dp[n];
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
