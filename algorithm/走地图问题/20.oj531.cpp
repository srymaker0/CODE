/*************************************************************************
	> File Name: 20.oj531.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Tue 02 Feb 2021 02:59:14 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int status, step;
};

int n, bit2[25], num[25], check[3000000], start;

void init() {
    bit2[0] = 1;
    for (int i = 1; i <= 20; i++) {
        bit2[i] = bit2[i - 1] * 2;
    }
} 

int main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            start += bit2[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt, t;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> t;
            num[i] += bit2[t];
        }
    }
    queue<node> que;
    que.push((node){start, 0});
    check[start] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.status == 8) {
            cout << temp.step << endl;
            return 0;
        }
        for (int i = 1; i <= 20; i++) {
            if ((temp.status & bit2[i]) == 0) {
                int t = temp.status + bit2[i];
                t &= ~num[i];
                if (check[t] == 0) {
                    check[t] = 1;
                    que.push((node){t, temp.step + 1});
                }
            }
        }
    }
    return 0;
}
