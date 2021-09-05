/*************************************************************************
	> File Name: 378.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 25 Nov 2020 09:01:27 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else if (s[i] == ')') {
            if (sta.empty() && sta.top() != '(') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        } else if (s[i] == ']') {
            if (sta.empty() && sta.top() != '[') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        } else if (s[i] == '}') {
            if (sta.empty() && sta.top() != '{') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        }
    }
    if (sta.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
