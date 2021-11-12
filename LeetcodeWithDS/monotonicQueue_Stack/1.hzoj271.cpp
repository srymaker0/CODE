/*************************************************************************
	> File Name: 1.hzoj271.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Nov 2021 08:47:48 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    deque<int> q;       // 双端队列
    for (int i = 0; i < n; i++) {
        // 入队->队列不为空，若当前元素比队尾元素小，则需要踢出
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);                             // 注意放入的是坐标
        if (i - q.front() == k) q.pop_front();      // 判断窗口长度，超出则踢出队首元素
        if (i + 1 < k) continue;
        if (i + 1 > k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] < arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        if (i + 1 > k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    return 0;
}
