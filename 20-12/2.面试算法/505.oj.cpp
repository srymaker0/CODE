/*************************************************************************
	> File Name: 505.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Nov 2020 06:36:12 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[100005];
int n;

bool cmp(const string &a, const string &b) {//保证任意2个元素 都是前面的字典序大于后面的 
    return a + b > b + a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
