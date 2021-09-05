/*************************************************************************
	> File Name: 5.quick_pc.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 14 May 2021 08:30:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *fa, n;                    // size记录根节点所在子树的节点数量
    UnionSet(int n ) : n(n) {
        fa = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (fa[x] == x) return x;
        int root = find(fa[x]);
        fa[x] = root;
        return root;
    }
    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return ;
        fa[ra] = rb;
        return ;
    }
};

int main() {


    return 0;
}
