/*************************************************************************
	> File Name: 240.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 18 Nov 2020 02:15:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int num[10] = {0, 1};
char mmap[3000][3000];

//第n项的长度为（n-1）* 3
void init() {
    for (int i = 2; i <= 7; i++) {
        num[i] = num[i - 1] * 3;
    }
}

//二维数组 抽象为坐标
//1 2  x x
// 4    x
//3 5  x x
//n != 1时 可以分解为5(n - 1)的问题
void func(int x, int y, int n) {
    if (n == 1) {
        mmap[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);//1的坐标
    func(x, y + num[n] / 3 * 2, n - 1);//2的坐标
    func(x + num[n] / 3 * 2, y, n - 1);//3
    func(x + num[n] / 3, y + num[n] / 3, n - 1);//4
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
}

int main() {
    init();
    func(1, 1, 7);
    int t;
    while (cin >> t) {
        if (t == -1) {
            break;
        }
        for (int i = 1; i <= num[t]; i++) {
            for (int j = 1; j <= num[t]; j++) {
                if (mmap[i][j] == 'X') {
                    cout << 'X';
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}
