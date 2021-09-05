/*************************************************************************
	> File Name: 10.e18.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Dec 2020 07:54:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[20][20];

int main() {
    n = 15;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    //int ans = 0;
    for (int i = n - 1; i >= 1; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
            //ans = max(ans, num[i][j]);
        }
    }
    //cout << ans << endl;
    cout << num[1][1] << endl;
    return 0; 
}
