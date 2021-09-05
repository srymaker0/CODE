/*************************************************************************
	> File Name: 2.oj562.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Tue 19 Jan 2021 06:18:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans ^= t;
    }
    cout << ans << endl;
    return 0;
}
