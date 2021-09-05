/*************************************************************************
	> File Name: 02.oj166字符串操作1.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 02 Mar 2021 03:53:52 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> n >> s2;
    if (s1.size() > 100) {
        cout << 100 << endl;
    } else {
        cout << s1.size() << endl;
    }
    s1.insert(n - 1, s2);
    cout << s1 << endl;
    cout << s1.size() - s1.rfind("x") << endl;
    return 0;
}
