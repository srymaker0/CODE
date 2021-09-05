/*************************************************************************
	> File Name: 3.e4.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 06:51:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int a, b;
int func(int n) {
    int t = n, temp = 0;
    while(n) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return t == temp; 
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (func(t) && ans < t) {
                ans = t;
                a = i, b = j;
            }
        }
    }
    cout << a << " " << b << endl;
    cout << ans << endl;
    return 0;
}
