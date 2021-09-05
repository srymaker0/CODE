/*************************************************************************
	> File Name: 12.oj386.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Dec 2020 06:33:08 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

struct node {
    int cnt;
    int num;
};

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}

int n, m;
node wm[100005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wm[i].num);
        wm[i].cnt = i + 1;
    }
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1, flag = 0;
        scanf("%d", &t);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (wm[mid].num == t) {
                printf("%d\n", wm[mid].cnt);
                flag = 1; //没找到答案
                break;
            }
            if (wm[mid].num > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (flag) cout << 0 << endl;
    }
    return 0;
}
