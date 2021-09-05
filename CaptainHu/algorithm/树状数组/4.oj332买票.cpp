/*************************************************************************
	> File Name: 4.oj332买票.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 21 Feb 2021 12:12:12 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 200000
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

int n;
int cnt[MAX_N + 5], val[MAX_N + 5], ind[MAX_N + 5], ans[MAX_N + 5];

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i] >> val[i];
        add(i, 1, n);
    }
    return ;
}

int binary_search(int n, int x) {
    int head = 1, tail = n, mid;
    while (head != tail) {
        mid = (head + tail) >> 1;
        if (query(mid) < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

void solve() {
    for (int i = n; i >= 1; i--) {
        ind[i] = binary_search(n, cnt[i] + 1);
        add(ind[i], -1, n);
        ans[ind[i]] = val[i];
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

int main() {
    read();
    solve();
    output();
    return 0;
}
