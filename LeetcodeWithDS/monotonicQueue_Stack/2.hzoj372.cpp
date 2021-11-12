/*************************************************************************
	> File Name: 2.hzoj372.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Nov 2021 09:37:11 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    deque<int> q1, q2;
    int p;
    for (p = 0; p < n; p++) {
        while (q1.size() && q1.back() > a[p]) q1.pop_back();
        while (q2.size() && q2.back() > b[p]) q2.pop_back();
        q1.push_back(a[p]);
        q2.push_back(b[p]);
        if (q1.size() != q2.size()) break;
    }
    cout << p << endl;
    return 0;
}
