/*************************************************************************
	> File Name: 504.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sat 28 Nov 2020 03:41:50 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string str;
int n;

int main() {
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') flag = 1;
        if (flag == 1) cout << str[i];
    }
    cout << endl;
    return 0;
}
