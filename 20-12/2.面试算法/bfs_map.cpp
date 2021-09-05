/*************************************************************************
	> File Name: bfs_map.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 20 Nov 2020 02:37:26 PM CST
 ************************************************************************/
//广搜走地图 可以解决用最少的步数走到终点
#include <iostream>
#include <queue>
using namespace std;

//自定义结构 搜索的时候用
struct node {
    int x, y, step;
};

int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    queue<node> que;
    que.push((node){sx, sy, 0});//起始状态
    //当队列不为空时 每次拿出队首元素的状态 然后向4个方向转移
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;//去重
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
