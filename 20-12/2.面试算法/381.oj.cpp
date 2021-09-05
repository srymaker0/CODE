/*************************************************************************
	> File Name: 381.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Nov 2020 02:36:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <string>
#include <algorithm>

struct person {
    string name;
    int num, avg, cla, paper, m;
    char off, west;    
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
    int t = 0;
    if (stu[x].avg > 80 && stu[x].paper >= 1) t += 8000;
    if (stu[x].avg > 85 && stu[x].cla > 80) t += 4000;
    if (stu[x].avg > 90 ) t += 2000;
    if (stu[x].avg > 85 && stu[x].west == 'Y') t += 1000;
    if (stu[x].cla > 80 && stu[x].off == 'Y') t += 850;
    return t;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].avg >> stu[i].cla >> stu[i].off >> stu[i].west >> stu[i].paper;
        stu[i].num = i;
        stu[i].m = func(i);
        ans += stu[i].m;
    }

    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl << stu[0].m << endl << ans << endl;
    return 0;
}
