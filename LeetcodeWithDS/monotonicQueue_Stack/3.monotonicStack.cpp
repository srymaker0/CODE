/*************************************************************************
	> File Name: 3.monotonicStack.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Nov 2021 07:40:58 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void output(vector<int> &arr, const char *msg) {
    printf("%s", msg);
    for (auto x : arr) {
        printf("%5d", x);
    }
    printf("\n");
    return ;
}

int main() {
    int n;
    cin >> n;
    vector<int> ind(n);
    vector<int> arr(n);
    vector<int> pre(n), next(n);
    stack<int> s;
    for (int i = 0; i < n; i++) ind[i] = i;
    for (int i = 0, a; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        // 单调递增 当前元素比栈顶元素小——违反单调性
        while (s.size() && arr[i] < arr[s.top()]) {
            next[s.top()] = i;              // 记录每个元素右边第一个比它小的元素的下标
            s.pop();                        // 弹出栈顶元素
        }
        if (s.size() == 0) pre[i] = -1;     // 栈为空 说明当前元素为第一个，左边没有比它小的
        else pre[i] = s.top();              // 否则，记录每个元素左边第一个比它小的元素的下标
        s.push(i);                          // 将当前元素压入栈
    }
    // 剩余的元素为区间最值，后面没有比它小的元素
    while (s.size()) next[s.top()] = n, s.pop();
    output(ind, "ind : ");
    output(arr, "now : ");
    output(pre, "pre : ");
    output(next, "next : ");
    return 0;
}
