/*************************************************************************
	> File Name: 6.e14.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 08:34:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long func(long long n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return func(n / 2) + 1;
    }
    return func(3 * n + 1) + 1;
}

int main() {
    long long ans = 1;
    for (long long i = 1; i <= 1000000; i--) {
        if (func(ans) < func(i)) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
