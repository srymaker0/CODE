/*************************************************************************
	> File Name: 1.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Nov 2020 01:57:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int ans = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans += i;
        } 
    }
    cout << ans << endl;
    return 0;
}
