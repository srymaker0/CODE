/*************************************************************************
	> File Name: 4.oj223.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 21 Jan 2021 04:49:26 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAX_N 10000
#define define_mid long long mid = (l + r) >> 1

//long long flag = 0;

struct {
    long long sum, tag;
} tree[MAX_N << 2];
long long arr[MAX_N + 5];

void update(long long ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    return ;
}

void down(long long ind, long long l, long long r) {
    if (tree[ind].tag) {
        long long val = tree[ind].tag;
        define_mid;
        tree[ind << 1].sum += val * (mid - l + 1);
        tree[ind << 1].tag += val;
        tree[ind << 1 | 1].sum += val * (r - mid);
        tree[ind << 1 | 1].tag += val;
        tree[ind].tag = 0;
    }
    return ;
}

void build_tree(long long ind, long long l, long long r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    define_mid;
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);
    return ;
}

void modify(long long ind, long long l, long long r, long long x, long long y, long long val) {
    //flag && printf(" ");
    if (x <= l && y >= r) {
        tree[ind].sum += val * (r - l + 1);
        tree[ind].tag += val;
        return ;
    }
    down(ind, l, r);
    define_mid;
    if (mid >= x) {
        modify(ind << 1, l, mid, x, y, val);
    }
    if (mid < y) {
        modify(ind << 1 | 1, mid + 1, r, x, y, val);
    }
    update(ind);
    return ;
}

long long query(long long ind, long long l, long long r, long long x, long long y) {
    //flag && printf(" ");
    if (x <= l && y >= r) {
        return tree[ind].sum;
    }
    down(ind, l, r);
    define_mid;
    long long ans = 0;
    if (mid >= x) {
        ans += query(ind << 1, l, mid, x, y);
    }
    if (mid < y) {
        ans += query(ind << 1 | 1, mid + 1, r, x, y);
    }
    return ans;
}

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++){
        scanf("%lld", arr + i);
    }
    build_tree(1, 1, n);
    long long a, b, c, d;
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        switch (a) {
            case 1: {
                scanf("%lld", &d);
                modify(1, 1, n, b, c, d);
            } break;
            case 2: {
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n", query(1, 1, n, b, c));
            } break;
        }
    }
    return 0;
}
