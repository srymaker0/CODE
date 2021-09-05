/*************************************************************************
	> File Name: 5.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Nov 2020 03:16:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int ans = 0, t;
    for (int i = 2520; i <= 50000; i++) {
        t = i;
        for (int j = 1; j <= 20; j++) {
            if (t % j == 0) {
                ans = max(ans, t);
            } else {
                break;
            }
        } 
    }
    cout << ans << endl;
    return 0;
}
