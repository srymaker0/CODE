/*************************************************************************
	> File Name: 2.e.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 06:40:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//int num[1000005]

int main() {
    /*
    num[1] = 1, num[2] = 2;
    for (int i = 3; 1; i++) {
        num[i] = num[i - 1] + num[i - 2];
        if (num[i] >= 4000000) break;
    }

    long long ans = 0;
    for (int i = 1; 1; i++) {
        if (num[i] % 2 == 0) ans += num[i];
        if (num[i] >= 4000000) break;
    }
    cout << ans << endl;
    */
    int a = 1, b = 2, ans = 0;
    while (b <= 4000000) {
        if (b % 2 == 0) ans += b;
        b = a + b;
        a = b - a;
    }
    cout << ans << endl;
    return 0;
}
