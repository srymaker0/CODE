/*************************************************************************
	> File Name: 1.oj329弱化的整数问题.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 20 Feb 2021 04:06:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_N 100000
int c[MAX_N + 5];
#define lowbit(x) (x & -x)

void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int n, pre = 0, a, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a - pre, n);
        pre = a;
    }
    scanf("%d", &m);
    char s;
    int l, r, x;
    for (int i = 0; i < m; i++) {
        getchar();
        scanf("%c", &s);
        switch (s) {
            case 'C': {
                scanf("%d%d%d", &l, &r, &x);
                add(l, x, n);
                add(r + 1, -x, n);
            } break;
            case 'Q': {
                scanf("%d", &x);
                cout << query(x) << endl;
            } break;
        }
    }
    return 0;
}
