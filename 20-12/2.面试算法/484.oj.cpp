/*************************************************************************
	> File Name: 484.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Nov 2020 04:22:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[130];
char str[1005];

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
        for (int j = 'Z'; i > 'A'; i--) {
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
    return 0;
}
