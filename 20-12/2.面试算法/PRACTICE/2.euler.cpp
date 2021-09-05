/*************************************************************************
	> File Name: 2.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Nov 2020 02:45:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a = 1, b = 1, c = 2, ans = 0;
    while (c < 4000000) {
        if (c % 2 == 0) {
            ans += c;
        }
        c = b + c;
        a = b;
        b = c - b;
    }
    cout << ans << endl;


    return 0;
}
