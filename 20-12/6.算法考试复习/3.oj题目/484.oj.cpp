/*************************************************************************
	> File Name: 484.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sat 28 Nov 2020 02:06:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int num[130];
char str[1000];

int main() {
    while (cin >> str) {
        for (int i = 0; str[i]; i++) {
            num[str[i]]++;
        }
    }
    int mmax = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        mmax = max(mmax, num[i]);
    } 
    for (int i = mmax; i > 0; i--) {
        int ind = 'A';
        for (int j = 'Z'; j > 'A'; j--) {
            if (num[j] >= i) {
                ind = j;
                break;
            }
        }
        for (int j = 'A'; j <= ind; j++) {
            if (j != 'A') {
                cout << " ";
            }
            if (num[j] >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        if (i != 'A') {
            cout << " ";
        }
        cout << i;
    }
    cout << endl;
    return 0;
}
