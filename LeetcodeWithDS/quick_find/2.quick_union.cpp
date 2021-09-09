/*************************************************************************
	> File Name: 2.quick_union.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 14 May 2021 07:25:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *boss, n;
    UnionSet(int n) : n(n) {
        boss = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            boss[i] = i;
        }
    }
    int find(int x) {
        if (boss[x] == x) return x;         // 若根节点是自己，则返回自己
        return find(boss[x]);               // 否则一直找自己的根节点
    }
    void merge(int a, int b) {
        int fa = find(a), fb = find(b);     // 取各自的根节点
        if (fa == fb) return ;              // 若一样，说明在一个集合中
        boss[fa] = fb;                      // 合并    
        return ;
    }
};


int main() {

    return 0;
}
