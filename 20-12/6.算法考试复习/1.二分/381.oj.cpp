/*************************************************************************
	> File Name: 381.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Mon 23 Nov 2020 01:58:11 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct person{
    string name;
    int num, avg, cla, t, m;
    char sl, ws;
};

bool cmp(person a, person b) {
    if (a.m == b.m) {
        return a.num < b.num;
    }
    return a.m > b.m;
}

int n, ans; 
person stu[105];

int func(int x) {
    int ss = 0;
    if (stu[x].avg > 80 && stu[x].t >= 1) ss += 8000;
    if (stu[x].avg > 85 && stu[x].cla > 80) ss += 4000;
    if (stu[x].avg > 90) ss += 2000;
    if (stu[x].avg > 85 && stu[x].ws == 'Y') ss += 1000;
    if (stu[x].cla > 80 && stu[x].sl == 'Y') ss += 850;
    return ss;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stu[i].name >> stu[i].avg >> stu[i].cla >> stu[i].sl
        >> stu[i].ws >> stu[i].t;
        stu[i].num = i;
        stu[i].m = func(i);
        ans += stu[i].m;
    }
    sort(stu + 1, stu + n + 1, cmp);
    cout << stu[1].name << endl << stu[1].m << endl << ans << endl;
    return 0;
}
