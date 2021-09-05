/*************************************************************************
	> File Name: 15.oj303.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 01 Mar 2021 03:56:31 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node {
    int x, y, step;
};
int n, m, num[1005][1005];
char mmap[1005][1005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

int main() {
    cin >> n >> m;
    memset(num, -1, sizeof(num));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});
                num[i][j] = 0;
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] != 0 && num[x][y] == -1) {
                num[x][y] = temp.step + 1;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            j != 1 && cout << " ";
            cout << num[i][j];
        }
        cout << endl;
    }
    return 0;
}
