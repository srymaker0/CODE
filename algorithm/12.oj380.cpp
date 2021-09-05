/*************************************************************************
	> File Name: 12.oj380.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Dec 2020 06:06:36 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct node {
    int cnt;
    string num;
};

bool cmp(const node &a, const node &b) {
    if (a.num.size() == b.num.size()) {
        return a.num > b.num;
    }
    return a.num.size() > b.num.size();
}


int main() {
    int n;
    node bio[105];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bio[i].num;
        bio[i].cnt = i + 1;
    }
    sort(bio, bio + n, cmp);
    cout << bio[0].cnt << endl << bio[0].num << endl;
    return 0;
}
