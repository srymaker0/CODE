/*************************************************************************
	> File Name: 6.oj398.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Thu 21 Jan 2021 08:17:38 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, x, y;
int ans[450][450];
int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};

int main() {
    memset(ans, -1, sizeof(ans)); //按字节赋值
    cin >> n >> m >> x >> y;
    queue<node> que;
    que.push((node){x, y, 0});
    ans[x][y] = 0;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m || ans[x][y] != -1) continue;
            ans[x][y] = temp.step + 1;
            que.push((node){x, y, ans[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
