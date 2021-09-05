/*************************************************************************
	> File Name: 5.oj222.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 26 Dec 2020 07:27:25 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

#define MAX_N 10000

struct {
    int max_num;
    int l, r;
} tree[MAX_N << 2]; //开4倍大小 用完全二叉树
int arr[MAX_N + 5];

void update(int ind) {
    tree[ind].max_num = max(tree[ind << 1].max_num, tree[ind << 1 | 1].max_num);
    return ;
}

void build_tree(int ind, int l, int r) {
    tree[ind].l = l, tree[ind].r = r; //记录当前节点表示的区间
    //分治到只有一个值 记录下数组中l位置的值到线段树中
    if (l == r) { 
        tree[ind].max_num = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build_tree(ind * 2, l, mid);
    build_tree(ind * 2 + 1, mid + 1, r);
    update(ind);
    return ;
}

void modify(int ind, int k, int val) {
    if (tree[ind].l == tree[ind].r) {
        tree[ind].max_num = val;
        return;
    }
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (k <= mid) {
        modify(ind << 1, k, val);
    } else {
        modify(ind << 1 | 1, k, val);
    }
    update(ind);
    return ;
}

int query(int ind, int x, int y) {
    if (tree[ind].l >= x && tree[ind].r <= y) {
        return tree[ind].max_num;
    }
    int ans = INT_MIN;
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (mid >= x) {
        ans = max(ans, query(ind << 1, x, y));
    }
    if (mid < y) {
        ans = max(ans, query(ind << 1 | 1, x, y));
    }
    return ans;
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: modify(1, b, c); break;
            case 2: {
                if (b > c) {
                    cout << "-2147483648" << endl;
                    break;
                }
                printf("%d\n", query(1, b, c));
            } break;
        }
    }
    return 0;
}
