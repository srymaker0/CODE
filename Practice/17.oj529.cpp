/*************************************************************************
	> File Name: 17.oj529.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 05:00:29 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;
};

int n, m, mark[150][150];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[150][150];

int func() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!a) return 0;
    mark[a][b] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; 1; j++) {
            int x = a + dir[i][0] * j;
            int y = b + dir[i][1] * j;
            if (mmap[x][y] != 'O') break;
            mark[x][y] = 1;
        }
    }
    if (mark[c][d] == 1) {
        cout << 0 << endl;
        return 1;
    }
    queue<node> que;
    que.push((node){c, d, 0});
    mark[c][d] = 2;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mark[x][y] == 1) {
                cout << temp.step + 1 << endl;
                return 1;
            }
            if (mark[x][y] != 2 && mmap[x][y] == 'O') {
                que.push((node){x, y, temp.step + 1});
                mark[x][y] = 2;
            }
        }
    }
    cout << "Impossible!" << endl;
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    while (func()) {}
    return 0;
}
