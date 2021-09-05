/*************************************************************************
	> File Name: 16.UnionSet.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 27 Nov 2020 08:33:13 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct UnionSet {
    int *father;
    int *size; //记录相关的节点个数  weighted quick-union 优化
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1; //最开始相关的节点数为自己 = 1
    }
    return u;
}

int find(UnionSet *u, int x) {
    //if (u->father[x] == x) return x;//返回的是当前元素的代表元素
    //return find(u, u->father[x]);   //否则我们就递归去找它父亲的父亲

    //优化 ：路径压缩  找到最直接的父亲  在路径压缩面前 可以去掉按节点合并的优化操作 其效率差不多
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) swap(fa, fb); //当fa的节点个数小于fb的节点个数 交换它们 保证fa的节点数是最大的
    u->father[fb] = fa;   //把fa当做合并后的根节点
    u->size[fa] += u->size[fb];  //当fb作为子树时 fa整体的节点个数要加上fb的
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
                    break;
        }
    }
    clear(u);
    return 0;
}
