/*************************************************************************
	> File Name: 2sum_sort2.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Dec 2020 06:50:14 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

int n, target, num[100005];
unordered_map<int, int> m;

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        m[num[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int t = target - num[i];
        if (m.count(t)) {
            cout << i << " " << m[t] << endl;
            cout << num[i] << "\t" << t << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    return 0;
}
