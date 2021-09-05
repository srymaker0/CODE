/*************************************************************************
	> File Name: 14.oj387.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Dec 2020 07:19:55 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    int cnt;
    int num;
};

node wm[1005];
int n, m;

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wm[i].num);
        wm[i].cnt = i + 1;
    }
    wm[n].cnt = n, wm[n].num = 2000000000; //虚拟瓜堆 判断找不到的情况
    n++; //为了让虚拟瓜堆排序
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1;
        scanf("%d", &t);
        while (l != r) {
            int mid = (l + r) / 2;
            if (wm[mid].num >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", wm[l].cnt);
    }
    return 0;
}
