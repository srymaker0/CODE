/*************************************************************************
	> File Name: 387.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Mon 23 Nov 2020 03:30:30 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int cnt, num;
};

int n, m;
node wm[1000005];

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;
    }
    wm[n].cnt = 0;
    wm[n].num = 2100000000;
    sort(wm, wm + n + 1, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n;
        cin >> t;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (wm[mid].num >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << wm[l].cnt << endl;
    }
    return 0;
}

