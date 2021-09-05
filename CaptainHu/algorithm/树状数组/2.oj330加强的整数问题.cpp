/*************************************************************************
	> File Name: 2.oj330加强的整数问题.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 20 Feb 2021 04:21:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
long long c[2][MAX_N + 5];
#define lowbit(x) (x & -x)

void add(long long k, long long i, long long x, long long n) {
    while (i <= n) {
        c[k][i] += x;
        i += lowbit(i);
    }
    return ;
}

long long query(long long k, long long i) {
    long long sum = 0;
    while (i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}

void modify(long long i , long long x, long long n) {
    add(0, i, x, n);
    add(1, i, i * x, n);
    return ;
}

long long S(long long i) {
    return (i + 1) * query(0, i) - query(1, i);
}

int main() {
    long long n, m, l, r, d;
    char s[10];
    scanf("%lld%lld", &n, &m);
    for (long long i = 1, pre = 0, a; i <= n; i++) {
        scanf("%lld", &a);
        modify(i, a - pre, n);
        pre = a;
    }
    for (long long i = 0; i < m; i++) {
        scanf("%s", s);
        switch (s[0]) {
            case 'C': {
                scanf("%lld%lld%lld", &l, &r, &d);
                modify(l, d, n);
                modify(r + 1, -d, n);
            } break;
            case 'Q': {
                scanf("%lld%lld", &l, &r);
                printf("%lld\n", S(r) - S(l - 1));
            } break;
        }
    }
    return 0;
}
