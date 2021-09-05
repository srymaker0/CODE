/*************************************************************************
	> File Name: 477.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 27 Nov 2020 10:54:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int ans = 0, last = - 1;
    char s[105];
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            if (last != -1) {
                ans = max(ans, i - last);
            }
            last = i;
        }
    }
    cout << ans << endl;
    return 0;
}
