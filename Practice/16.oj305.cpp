/*************************************************************************
	> File Name: 16.oj529.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 04:28:52 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;
};
int n, m, sx, sy, ans;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, -1, 1, 1, -1, 1, -1, -1};
char mmap[105][105];

int main() {
    cin >> m >> n >> sy >> sx;
    sx = n - sx + 1;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    mmap[sx][sy] = 0;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        ans = temp.step;
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = '#';
                que.push((node){x, y, temp.step + 1});
            }
        } 
    }
    cout << ans << endl;
    return 0;
}
