/*************************************************************************
	> File Name: dfs_map.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 18 Nov 2020 04:37:45 PM CST
 ************************************************************************/
//深搜走地图问题 判断能不能从起点走到终点
#include <iostream>
using namespace std;

int n, m, sx, sy;//sx，sy 分别为起点横坐标和纵坐标
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; //0 1为一个方向 1 0为一个方向

int func(int x, int y) {
    for (int i = 0; i < 4; i++) {//每次往对应的方向去走
        int xx = x + dir[i][0];//新的横坐标
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == 'T') {
            return 1;
        }
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '#'; //避免重复搜索 
            if (func(xx, yy) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    //从(1, 1)这个点开始存 这样外面围了一圈0 不会走到地图外面
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            //如果是起点则记录起点的横纵坐标
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    if (func(sx, sy) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
