/*************************************************************************
	> File Name: 1.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Oct 2020 02:52:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    /*
     * 时间复杂度为O(n) 太慢了
    int ans = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 ||i % 5 == 0) {
            ans += i;
        }
    }
    */

    //用等差数列求 秒出
    int t3 = (3 + 999) * 333 / 2;
    int t5 = (5 + 995) * 199 / 2;
    int t15 = (15 + 990) * 66 / 2;
    cout << t3 + t5 - t15 << endl;
    return 0;
}
