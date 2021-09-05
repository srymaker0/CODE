/*************************************************************************
	> File Name: 8.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Nov 2020 04:18:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

char num[1005];
long long ans, zero_cnt, now = 1;

int main() {
    cin >> num;
    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            now *= num[i] - '0';
        } else {
            if (num[i] == '0') {
                zero_cnt++;
            } else {
                now *= num[i] - '0';
            }
            if (num[i - 13] == '0') {
                zero_cnt--;
            } else {
                now /= num[i - 13] - '0';
            }
        }
        if (zero_cnt == 0) {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
