/*************************************************************************
	> File Name: 14.oj529.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Mon 01 Feb 2021 05:01:34 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, check[150][150];
char mmap[150][150];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

void init(int x, int y) {
    check[x][y] = 2;
    for (int i = 0; i < 7; i++) {
        for (int j = 1; 1; j++) {
            int xx = x + dir[i][0] * j;
            int yy = y + dir[i][1] * j;
            if (mmap[xx][yy] != 'O') {
                break;
            }
            check[xx][yy] = 2;
        }
    }
} 

void bfs(int x, int y) {
    if (check[x][y] == 2) {
        cout << 0 << endl;
        return ;
    }
    queue<node> que;
    que.push((node){x, y, 0});
    check[x][y] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (check[xx][yy] == 2) {
                cout << temp.step + 1 << endl;
                return ;
            }
            if (mmap[xx][yy] == 'O' && check[xx][yy] == 0) {
                check[xx][yy] = 1;
                que.push((node){xx, yy, temp.step + 1});
            }
        }
    }
    cout << "Impossible!" << endl;
}

int func() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!a) return 0;
    memset(check, 0, sizeof(check));
    init(a, b);
    bfs(c, d);
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

