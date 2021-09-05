/*************************************************************************
	> File Name: 19.oj505.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Jan 2021 06:33:39 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int n;
string str[100005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}
