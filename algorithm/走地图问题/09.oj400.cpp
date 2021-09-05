/*************************************************************************
	> File Name: 9.oj400.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Sat 23 Jan 2021 05:58:10 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char mmap[505][505];
int dir[12][2] = {-2, -2, -2, -1, -2, 1, -2, 2, -1, 2, 1, 2, 2, 2, 2, 1, 2, -1, 2, -2, 1, -2, -1, -2};

struct node {
    int x, y, step;
};

int func(int x, int y) {
    queue<node> que;
    que.push((node){x, y, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx < 0 || yy < 0 || xx > x || yy > y) continue;
            if (mmap[xx][yy] == 'T') {
                memset(mmap, -1, sizeof(mmap));
                mmap[1][1] = 'T';
                return temp.step + 1;
            }
            if (mmap[xx][yy] == -1) {
                que.push((node){xx, yy, temp.step + 1});
                mmap[xx][yy] = '0';
            }
        }
    }
}

int main() {
    memset(mmap, -1, sizeof(mmap));
    mmap[1][1] = 'T';
    for (int i = 0; i < 2; i++) {
        int sx, sy;
        cin >> sx >> sy;
        cout << func(sx, sy) << endl;
    }


    return 0;
}
