/*************************************************************************
	> File Name: bfs.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sun 29 Nov 2020 10:33:26 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct point {
    int x, y;
    point(int a, int b):x(a), y(b) {} 
};

const int max_n = 2005;
char mmap[max_n][max_n];
int d[8] = {0, 1, 0, -1, 1, 0, -1, 0};

int mem[max_n][max_n];
int n, m;

int bfs(int x, int y, int t) {
    int cou = 1;
    queue<point> q;
    point p(x, y);
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (i = 0; i < 8; i++) {
            int tx = p.x + d[i];
            int ty = p.y + d[i + 1];
            if (tx > 0 && tx <- n && ty > 0 && ty <= n && mmap[p.x][p.y] != mmap[tx][ty] && mem[tx][ty] == 0) {
                point p1(tx, ty);
                q.push(p1);
                mem[tx][ty] = t;
                cou++;
            }
        }
    }
    return 
}
