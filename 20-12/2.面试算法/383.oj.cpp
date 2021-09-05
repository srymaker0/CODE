/*************************************************************************
	> File Name: 383.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 06:09:34 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;


int main() {
    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 1; i <= x; i++) {
        qx.push(i);    
    }
    for (int i = 1; i <= y; i++) {
        qy.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << qx.front() << " " <<qy.front() << endl;
        qx.push(qx.front());
        qy.push(qy.front());
        qx.pop();
        qy.pop();
    }
    return 0;
}
