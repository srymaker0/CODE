/*************************************************************************
	> File Name: 1.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 06:18:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int t3, t5, t15;
    t3 = (3 + 999) * 333 /2;
    t5 = (5 + 995) * 199 /2;
    t15 = (15 + 990) * 66 /2;
    cout << t3 + t5 - t15 << endl;
}

/*
int main() {
    int ans = 0;
    for (int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;
}
*/
