/*************************************************************************
	> File Name: 23.oj575.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 18 Jan 2021 05:30:26 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        m[s] = t;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
    return 0;
}
