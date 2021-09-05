/*************************************************************************
	> File Name: 15.eluer.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Nov 2020 03:41:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    long long ans = 1;
    for (int i = 40, j = 1; i > 20; i--, j++) {
        ans *= i;
        ans /= j;
    } 
    cout << ans << endl;
    return 0;
}
