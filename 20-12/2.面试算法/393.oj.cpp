/*************************************************************************
	> File Name: 393.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Nov 2020 06:20:08 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
double num[10005], tr;

int func(double len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;
    }
    return s;
    
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 0; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    double l = 0, r = tr;
    while (r - l > 0.00001) {
        double mid = (l + r) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.2f\n", (int)(l * 100) / 100.0);
    return 0;
}
