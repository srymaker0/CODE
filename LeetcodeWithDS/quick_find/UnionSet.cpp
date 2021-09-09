/*************************************************************************
	> File Name: UnionSet.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 14 May 2021 09:53:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *fa, n;
    UnionSet(int n) : n(n) {
        fa = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};
