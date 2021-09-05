/*************************************************************************
	> File Name: 2sum_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Dec 2020 06:13:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, target, num[100005];

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int t = num[l] + num[r];
        if (t == target) {
            cout << l << "\t" << r << endl;
            cout << num[l] << "\t" << num[r] << endl;
        }
        if (t > target) {
            r--;
        } else {
            l++;
        }
    }
    cout << "not found" << endl;
    /*
    for (int i = 0; i < n - 1; i++) {
        int l = i + 1, r = n - 1, t = target - num[i];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] == t) {
                cout << i << "\t" << mid << endl;
                cout << num[i] << "\t" << num[mid] << endl;
                return 0;
            }
            if (num[mid] > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    */
    return 0;
}
