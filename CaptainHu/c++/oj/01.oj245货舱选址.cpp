/*************************************************************************
	> File Name: 01.oj245货舱选址.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 02 Mar 2021 03:34:30 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int pos = arr[n / 2], sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += abs(arr[i] - pos);
    }
    cout << sum << endl;
    return 0;
}
