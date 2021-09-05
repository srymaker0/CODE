/*************************************************************************
	> File Name: 1.happy.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 19 Mar 2021 08:40:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int getNext(int x) {
    int t = 0;
    while (x) {
        t += (x % 10) * (x % 10);
        x /= 10;
    }
    return t;
}

int happyN(int x) {
    int p = x, q = x;
    do {
        p = getNext(p);
        q = getNext(getNext(q));
    } while (p != q && q != 1);
    if (q == 1 || getNext(q) == 1) return 1;
    return 0;
}

int main() {
    int n = 100000, sum = 0;
    cout << happyN(19) << endl;
    for (int i = 0; i < n; i++) {
        if (happyN(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
