/*************************************************************************
	> File Name: 480.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Nov 2020 03:05:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct node {
    char s[4];//这局的情况
    int num1, num2, flag;//num1 第一局的分数 num2 剩下两局的 
};

node b[15];

int main() {
    int ans = 0;
    for (int i = 0; cin >> b[i].s; i++) {
        if (b[i].s[0] == '/') {//直接
            b[i].num1 = b[i].num2 = 10;
            b[i].flag = 2;
        } else if (b[i].s[1] == '/') {//间
            b[i].num1 = b[i].s[0] - '0';
            b[i].num2 = 10;
            b[i].flag = 1;
        } else {
            b[i].num1 = b[i].s[0] - '0';
            b[i].num2 = b[i].s[1] - '0' + b[i].num1;
            b[i].flag = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += b[i].num2;
        if (b[i].flag == 1) {
            ans += b[i + 1].num1;
        } else if (b[i].flag == 2) {
            if (b[i + 1].flag == 2) {
                ans += 10 + b[i + 2].num1;
            } else {
                ans += b[i + 1].num2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
