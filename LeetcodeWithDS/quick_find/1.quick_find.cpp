/*************************************************************************
	> File Name: 1.quick_find.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 14 May 2021 07:01:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *color, n;
    UnionSet(int n) : n(n) {
        color = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            color[i] = i;                      // 初始化颜色
        }
    }
    int find(int x) {
        return color[x];
    }
    void merge(int a, int b) {
        if (color[a] == color[b]) return ;     // 说明在一个集合中
        int cb = color[b];                     // 我们把a集合颜色染成b集合的颜色
        for (int i = 0; i <= n; i++) {
            if (color[i] == cb) color[i] = color[a];        
        }
    }
    return ;
};


int main() {



    return 0;
}
