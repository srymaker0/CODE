/*************************************************************************
	> File Name: revers.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sun 29 Nov 2020 08:49:07 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k = 0;
    getline(cin, s);
    s = s + " ";
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ' || s[i] == '.') {
            for (int j = i - 1; j >= k; j--) {
                    cout << s[j];
            }
            if (s[i] != '.') cout << " ";
            else cout << ".";
            k = i + 1;
        }
    }
    return 0;
}
