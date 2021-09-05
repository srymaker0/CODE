/*************************************************************************
	> File Name: 7.oj396.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Thu 21 Jan 2021 08:48:38 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

int n, num[50][50];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    queue<node> que;
    que.push((node){0, 0});
    num[0][0] = 3;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || y < 0 || x > n + 1 || y > n + 1 || num[x][y] != 0) continue;
            num[x][y] = 3;
            que.push((node){x, y});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) {
                cout << " ";
            }
            if (num[i][j] == 0) {
                cout << 2;
            } else if (num[i][j] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}
