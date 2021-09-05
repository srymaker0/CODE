/*************************************************************************
	> File Name: 04.oj287合并果子.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 02 Mar 2021 07:09:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct CMP {
public:
    bool operator()(int a, int b) {
        return a > b;                             //优先队列默认升序，弹出元素从尾部弹出， 要想弹出小元素就要降序
    }
};

int main() {
    priority_queue<int, vector<int>, CMP> q;       //priority_queue是一个模版
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        q.push(a);
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        sum += a + b;
        q.push(a + b);
    }
    cout << sum << endl;
    return 0;
}

