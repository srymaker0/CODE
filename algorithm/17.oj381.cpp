/*************************************************************************
	> File Name: 17.oj381.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Dec 2020 02:32:02 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct person {
    char name[100], sl, ws;
    int avg, score, paper;
    int m, cnt;
};

person p[105];

bool cmp(const person &a, const person &b) {
    if (a.m == b.m) return a.cnt < b.cnt;
    return a.m > b.m;
}

int n, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].avg
            >> p[i].score >> p[i].sl
        >> p[i].ws >> p[i].paper;
        p[i].cnt = i;
    }
    for (int i = 0; i < n; i++) {
        if (p[i].avg > 80 && p[i].paper >= 1) p[i].m += 8000;
        if (p[i].avg > 85 && p[i].score > 80) p[i].m += 4000;
        if (p[i].avg > 90 ) p[i].m += 2000;
        if (p[i].avg > 85 && p[i].ws == 'Y') p[i].m += 1000;
        if (p[i].score > 80 && p[i].sl == 'Y') p[i].m += 850;
        ans += p[i].m;
    }
    sort(p, p + n, cmp);
    cout << p[0].name << endl << p[0].m << endl << ans << endl;
    return 0;
}
