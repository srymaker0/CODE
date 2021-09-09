/*************************************************************************
	> File Name: 4.weighted_quick_pc.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 14 May 2021 08:30:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *fa, *size, n;                    // size记录根节点所在子树的节点数量
    UnionSet(int n ) : n(n) {
        fa = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
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
        if (size[ra] < size[rb]) {        // 谁小谁做为儿子
            fa[ra] = fa[rb];
            size[rb] += size[ra];         // 爸爸要加上儿子的节点数量
        } else {
            fa[rb] = fa[ra];
            size[ra] += size[rb];
        }
    }
};

int main() {


    return 0;
}
