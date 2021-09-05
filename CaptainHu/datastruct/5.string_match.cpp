/*************************************************************************
	> File Name: 5.string_match.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 20 Jan 2021 03:25:28 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//暴力匹配法
int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;  //用于判断是否匹配成功
        /*
        for (int j = 0; t[i]; j++) {
            if (s[i + j] == t[j]) continue;
            flag = 0; 
            break;
        }
        */
        //优化了上面那段代码
        for (int j = 0; t[i] && flag; j++) {
            flag = flag && (s[i + j] && s[i + j] == t[j]);
        }
        if (flag == 1) return i;  //返回匹配成功的首地址
    }
    return -1;
}

int getNext(const char *t, int &j, char input, int *next) {
    while (j != - 1 && t[j + 1] != input) j = next[j]; //input为当前输入的字符
    if (t[j + 1] == input) j += 1;
    return j;
}

int kmp(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * n + 1);
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) next[i] = getNext(t, j, t[i], next); //状态机的状态转移过程
    for (int i = 0, j = -1; s[i]; i++) {
        if (getNext(t, j, s[i], next) != n - 1) continue; //若相等则说明匹配成功 否则一直遍历
        return i - n + 1;
    }
    free(next);
}

/*
void getNext(const char *t, int *next) {
    next[0] = -1; //这里第一位肯定等于-1 因为第一位无法匹配
    int j = -1; //j指向的是上一位next数组的值
    for (int i = 1; t[i]; i++) {
        //当j不等于-1 表示匹配到了一样的字符 如果后面第i位不匹配 则进行next[next[i]]操作
        while (j != - 1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1; //如果这两位字符相等 说明找到了前缀 并记录前缀位置 
        next[i] = j; //在这里进行记录当前t[i]最长匹配的前缀位置
    }
    return ;
}

int kmp(const char *s, const char *t) {
    int n = strlen(t);  //t的长度
    int *next = (int *)malloc(sizeof(int) * n + 1);
    getNext(t, next);
    for (int i = 0, j = -1; s[i]; i++) { //j表示当前匹配到了模式串的第几位
        while (j != -1 && s[i] - t[j + 1]) j = next[j]; 
        if (s[i] == t[j + 1]) j += 1;
        if (t[j + 1] == 0) return i - n + 1;
    }
    free(next);
    return -1;
}
*/

int sunday(const char *s, const char *t) {
    int offset[256]; //记录每一个字符在倒数第几位
    int n = strlen(t), m = strlen(s);
    //初始化
    for (int i = 0; i < 256; i++) offset[i] = n + 1; //假设都没有出现过 每一个字符是倒数n + 1位
    //遍历t串 在offset中记录每一位在倒数第几位
    for (int i = 0; t[i]; i++) offset[t[i]] = n - i;
    //文本串中剩余的部分比模式串要长这样才有意义 i + n <= m 
    for (int i = 0; i + n <= m; i += offset[s[i + n]]) { //s[i + n] 表示黄金对齐点位的字符
        int flag = 1; //模拟暴力匹配
        for (int j = 0; t[j] && flag; j++) {
            flag = flag && (s[i + j] == t[j]);
        }
        if (flag) return i;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("brute_force(%s, %s) = %d\n", s, t, brute_force(s, t));
        printf("kmp(%s, %s) = %d\n", s, t, kmp(s, t));
        printf("sunday(%s, %s) = %d\n", s, t, sunday(s, t));
    }
    return 0;
}
