/*************************************************************************
	> File Name: 516.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Nov 2020 08:23:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[100005], wcnt;
long long ans;
char str[100005];

int main() {
    cin >> n >> &str[1];
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'C') {
            num[i] = num[i - 1] + 1;
        } else {
            num[i] = num[i - 1];
        }
    }
    for (int i = n; i > 0; i--) {
        if (str[i] == 'W') {
            wcnt++;
        }
        if (str[i] == 'O') {
            ans += (long long)num[i - 1] * wcnt;
        }
    }
    cout << ans << endl;
    return 0;
}
