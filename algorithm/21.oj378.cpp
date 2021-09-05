/*************************************************************************
	> File Name: 21.oj378.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 18 Jan 2021 04:57:29 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> sta;
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else if (s[i] == ')') {
            if (!sta.empty() && sta.top() == '(') {
                sta.pop();
            } else {
                flag = 1;
                break;
            }
        } else if (s[i] == ']') {
            if (!sta.empty() && sta.top() == '[') {
                sta.pop();
            } else {
                flag = 1;
                break;
            }
        } else if (s[i] == '}') {
            if (!sta.empty() && sta.top() == '{') {
                sta.pop();
            } else {
                flag = 1;
                break;
            }
        }
    }
    if (!sta.empty()) {
        flag = 1;
    }
    if (flag == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}


