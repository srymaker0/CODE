/*************************************************************************
	> File Name: 22.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 2020 03:53:22 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n = 0;
    string name[6005];
    while (cin >> name[n]) {
        n++;
    }
    sort(name, name + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < name[i].size(); j++) {
            t += name[i][j] - 'A' + 1;
        }
        ans += t * (i + 1);
    }
    cout << ans << endl;
    return 0;
}
