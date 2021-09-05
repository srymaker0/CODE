/*************************************************************************
	> File Name: 2.floyd_hzoj_746.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 15 Jul 2021 08:53:43 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>     // memset
using namespace std;

int arr[1005][1005], n, m, s;

int main() {
    memset(arr, 0x3f, sizeof(arr));         // 初始化arr为一个极大值
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 去重，保留权值较小的
        if (arr[a][b] > c) {
            arr[a][b] = c;
            arr[b][a] = c;                  // 无向图，需要反过来再存一遍
        }
    }
    // floyd算法
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; j++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    // 输出
    for (int i = 1; i <= n; i++) {          
        arr[i][i] = 0;                      // 自己到自己的权值是0——邻接矩阵的对角线
        if (arr[s][i] == 0x3f3f3f3f) {      // 还是极大值，说明到不了
            cout << -1 << endl;
        } else {
            cout << arr[s][i] << endl;
        }
    }
}

