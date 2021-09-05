/*************************************************************************
	> File Name: 1.arr.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 15 Jul 2021 07:52:46 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int arr[105][105], n, m;

// 有向权值图
int main() {
    cin >> n >> m;
    // 存储
    for (int i = 0; i < m; i++) {
        int a, b, c;          // c 为权值  
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    // 输出
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";   // 输出点
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0) {
                cout << "{" << i << "-->" << j << ", " << arr[i][j] << "} ";
            }
        }
        cout << endl;
    }
    return 0;
}
