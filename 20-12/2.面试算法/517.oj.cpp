/*************************************************************************
	> File Name: 517.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Nov 2020 08:40:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = i; j <= (n - i) / 2; j++) {
            if (i + j > n - i - j) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
