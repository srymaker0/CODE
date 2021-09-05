/*************************************************************************
	> File Name: 05.oj256国王游戏.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 02 Mar 2021 08:15:11 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;      //一对整型

int main() {
    vector<PII> arr;
    int n;
    cin >> n;
    for (int i = 0, a, b; i <= n; i++) {
        cin >> a >> b;
        arr.push_back(PII(a, b));
    }
    sort(arr.begin() + 1, arr.end(),
        [](const PII &x,const PII &y){
            return x.first * x.second < y.first * y.second; 
        }
    );
    int p = arr[0].first, ans = 0;
    for (int i = 1; i <= n; i++) {
        int temp = p / arr[i].second;
        ans = max(ans, temp);
        p *= arr[i].first;
    }
    cout << ans << endl;
    return 0;
}
