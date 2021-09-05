/*************************************************************************
	> File Name: 14.oj400.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 12:05:36 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node {
    int x, y, step;
};
int n;
int dir[12][2] = {
    1, 2, 1, -2,
    -1, 2, -1, -2,
    2, 1, 2, -1,
    -2, 1, -2, -1,
    2, 2, 2, -2,
    -2, 2, -2, -2
};
int mmap[505][505];

int main() {
    memset(mmap, -1, sizeof(mmap));
    queue<node> que;
    que.push((node){1, 1, 0});
    mmap[1][1] = 0;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > 500 || y > 500 || mmap[x][y] != -1) continue;
            mmap[x][y] = temp.step + 1;
            que.push((node){x, y, temp.step + 1});
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << mmap[a][b] << endl;
    }
    return 0;
}
