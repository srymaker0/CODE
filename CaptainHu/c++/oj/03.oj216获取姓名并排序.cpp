/*************************************************************************
	> File Name: 03.oj216获取姓名并排序.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 02 Mar 2021 04:07:20 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    int n;
    map<string, int> h;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        h[s.substr(3, s.size())] += 1;           //船长偷懒了 这样写默认截取到字符串末尾
    }
    for (auto iter = h.begin(); iter != h.end(); iter++) {
        // iter迭代器 first指向map中的键(key)也就是string second指向的是值(value)-int
        for (int i = 0; i < iter->second; i++) cout << iter->first << endl;
    }
    return 0;
}
