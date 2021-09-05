/*************************************************************************
	> File Name: 01.match_char.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 22 Feb 2021 07:00:41 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


int brute_force_1(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] && s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int brute_force_2(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = (s[i + j] && s[i + j] == t[j]);
        }
        if (flag) return i;
    }
    return -1;
}

void getNext_1(const char *t, int *next) {
    next[0] = -1;
    int j = -1;
    for (int i = 1; t[i]; i++) {
        while (j != -1 && t[j + 1] - t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    return ;
}

int kmp_1(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (n + 1));
    getNext_1(t, next);
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && s[i] - t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j += 1;
        if (t[j + 1] == 0) return i - n + 1;
    }
    free(next);
    return -1;
}

int getNext_2(const char *t, int &j, char input, int *next) {
    while (j != -1 && t[j + 1] != input) j = next[j];
    if (t[j + 1] == input) j += 1;
    return j;
}

int kmp_2(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (n + 1));
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) next[i] = getNext_2(t, j, t[i], next);
    for (int i = 0, j = -1; s[i]; i++) {
        if (getNext_2(t, j, s[i], next) != n - 1) continue;
        return i - n + 1;
    }
    free(next);
    return -1;
}

int sunday(const char *s, const char *t) {
    int offset[256];
    int n = strlen(t), m = strlen(s);
    for (int i = 0; i < 256; i++) offset[i] = n + 1;
    for (int i = 0; t[i]; i++) offset[t[i]] = n - i;
    for (int i = 0; i + n <= m; i += offset[s[i + n]]) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = (s[i + j] == t[j]);
        }
        if (flag) return i;
    }
    return -1;
}

int shift_and(const char *s, const char *t) {
    int d[256] = {0}, n = 0;
    for (int i = 0; t[i]; n++, i++) d[t[i]] |= (1 << i);
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & d[s[i]];
        if (p & (1 << (n - 1))) return i - n + 1;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("brute_force_1(%s, %s) = %d\n", s, t, brute_force_1(s, t));
        printf("kmp_1(%s, %s) = %d\n", s, t, kmp_1(s, t));
        printf("sunday(%s, %s) = %d\n", s, t,sunday(s, t));
        printf("shift_and(%s, %s) = %d\n", s, t, shift_and(s, t));
        printf("---------------------------\n\n");
    }

    return 0;
}
