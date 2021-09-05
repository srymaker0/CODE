/*************************************************************************
	> File Name: 5.e8.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 07:41:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    char num[1005];
    cin >> num;
    long long ans = 0, now = 1, cnt = 0;
    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            now *= num[i] - '0';  // 减0为了变成整型
        } else {
            if (num[i] == '0')  cnt++;
            else now *= num[i] - '0';
            if (num[i - 13] == '0') cnt--; 
            else now /= num[i - 13] - '0';
        }
        if (cnt == 0) ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
