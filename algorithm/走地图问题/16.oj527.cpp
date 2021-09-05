/*************************************************************************
	> File Name: 16.oj527.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 08:39:15 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step, d;
};

int n, m, d, check[105][105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){1, 1, 0, d});
    for (int i = 0; i <= d; i++) {
        check[1][1][i] = 1;
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j <= temp.d; j++) {
                int x = temp.x + dir[i][0] * j;
                int y = temp.y + dir[i][1] * j;
                if (mmap[x][y] == 0) {
                    break;
                }
                if (x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                if (mmap[x][y] == 'P' && check[x][y][temp.d - j] == 0) {
                    check[x][y][temp.d - j] = 1;
                    que.push((node){x, y, temp.step + 1, temp.d - j});
                }
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && check[x][y][temp.d] == 0) {
                check[x][y][temp.d] = 1;
                que.push((node){x, y, temp.step + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
