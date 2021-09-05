/*************************************************************************
	> File Name: 519.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Nov 2020 06:15:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    long long ans = 0, left,right;
    cin >> left >> right;
    for (int i = 0; i < 10; i++) {//一堆数
        for (int j = 0; j < 10; j++) {//一个数
            if (i == j) {
                continue;
            }
            for (int k = 3; k <= 17; k++) {//数长
                for (int l = 1; l <= k; l++) {//位置
                    if (i == 0 && l != 1) {
                        break;
                    }
                    if (j == 0 && l == 1) {
                        continue;
                    }
                    long long t = 0;
                    for (int m = 1; m <= k; m++) {//构造优雅数
                        if (m == 1) {
                            t = t * 10 + j;
                        } else {
                            t = t * 10 + i;
                        }
                    }
                    if (left <= t && t <= right) {
                        ans++;
                    }
                }
            }
        }
    }

    return 0;
}
