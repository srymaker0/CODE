/*************************************************************************
	> File Name: 1.calculat.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 20 Apr 2021 02:51:49 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int calc(char *s, int l, int r) {
    int op = -1, pri = 10000 - 1, cur_pri, temp = 0;   //temp记录的是额外的优先级 +100 -100
    for (int i = l; i <= r; i++) {
        cur_pri = 10000;      //当前运算符优先级 设置一个默认值
        switch (s[i]) {
            case '+':
            case '-': cur_pri = 1 + temp; break;
            case '*':
            case '/': cur_pri = 2 + temp; break;
            case '(': temp += 100; break;        //入括号 优先级+100
            case ')': temp -= 100; break;        //出括号 优先级-100
        }
        if (cur_pri <= pri) {
            pri = cur_pri;
            op = i;     //找到优先级最小的运算符的位置
        }
    }
    //若下标为-1 将字符串转换成数字
    if (op == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    int a = calc(s, l, op - 1);   //以优先级最低的运算符开始向左递归运算
    int b = calc(s, op + 1, r);   //----------低--------------右--------
    // 根据运算符求值
    switch (s[op]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char s[100];
    while (~scanf("%[^\n]s", s)) {      //读入空格 
        getchar();   //吃掉换行符
        printf("%s = %d\n", s, calc(s, 0, strlen(s) - 1));
    }
    return 0;
}
