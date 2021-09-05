/*************************************************************************
	> File Name: 378.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 06:18:52 PM CST
 ************************************************************************/

#include<iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
            sta.push(s[i]);
        } else if (s[i] == ')') {
            if (sta.empty() || sta.top() != '(') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        } else if (s[i] == ']') {
            if (sta.empty() || sta.top() != '[') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        } else if (s[i] == '}') {
            if (sta.empty() || sta.top() != '{') {
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
