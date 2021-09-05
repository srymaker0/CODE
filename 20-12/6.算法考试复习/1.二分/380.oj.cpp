/*************************************************************************
	> File Name: 380.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Mon 23 Nov 2020 01:19:15 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int num;
    string s;
};

int n;
node p[105];


bool cmp(const node &a, const node &b) {
    if (a.s.size() == b.s.size()) {
        return a.s > b.s;
    }
    return a.s.size() > b.s.size();
}    



int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].s;
        p[i].num = i;
    }
    sort(p + 1, p + n + 1, cmp);
    cout << p[1].num << endl << p[1].s << endl;
    return 0;
}
