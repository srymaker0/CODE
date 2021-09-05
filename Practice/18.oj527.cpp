/*************************************************************************
	> File Name: 18.oj527.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 07:13:46 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step, d;
};
int n, m, d, mark[105][105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){1, 1, 0, d});
    for (int i = 0; i < d; i++) {
        mark[1][1][i] = 1;
    }
    while ()
    return 0;
}

