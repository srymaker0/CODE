/*************************************************************************
	> File Name: 18.oj388.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Dec 2020 03:11:16 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num1[100005], num2[100005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> num2[i];
    }
    sort(num2, num2 + m);
    long long sum = 0, f = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num2[mid] == num1[i]) {
                if (f == 1) cout << " ";
                f = 1;
                cout << num2[mid];
                sum += num2[mid];
                break;
            }
            if (num2[mid] < num1[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    } 
    cout << endl;
    cout << sum << endl;
    return 0;
}
