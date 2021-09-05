/*************************************************************************
	> File Name: 04.oj264最大矩形面积.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 17 Feb 2021 07:20:52 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_N 100000
long long s[MAX_N + 5], top;
long long h[MAX_N + 5], n;
long long l[MAX_N + 5], r[MAX_N + 5];

void read() {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", h + i);
    }
    return ;
}

long long solve() {
    h[0] = h[n + 1] = -1;
    top = -1;
    s[++top] = 0;
    for (long long i = 1; i <= n; i++) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (long long i = n; i >= 1; i--) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
