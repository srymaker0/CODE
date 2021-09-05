/*************************************************************************
	> File Name: 18.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Nov 2020 02:55:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[20][20], ans[20][20];

int main() {
    n = 1;
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    /*把这道题抽象成直角三角形 从上往下求
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + num[i][j];
            fin = max(fin, ans[i][j]);
        }
    }
    cout << fin << endl;
    */
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i + 1][j], ans[i + 1][j + 1]) + num[i][j];
        }
    }
    cout << ans[1][1] << endl;
    return 0;
}
