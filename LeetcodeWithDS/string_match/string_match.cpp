/*************************************************************************
	> File Name: string_match.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Jan 2022 04:25:48 PM CST
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int brute_force(const char *text, const char *pattern) {
    for (int i = 0; text[i]; i++) {
        int flag = 1;
        for (int j = 0; pattern[j]; j++) {
            if (text[i + j] == pattern[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

void GetNext(const char *pattern, int *next) {
    next[0] = -1;
    for (int i = 1, j = -1; pattern[i]; ++i) {
        while (j != -1 && pattern[i] - pattern[j + 1]) j = next[j];
        if (pattern[i] == pattern[j + 1]) j += 1;
        next[i] = j;
    }
    return ;
}

int kmp_1(const char *text, const char *pattern) {
    int n = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * n);
    GetNext(pattern, next);
    for (int i = 0, j = -1; text[i]; i++) {
        while (j != -1 && text[i] - pattern[j + 1]) j = next[j];
        if (text[i] == pattern[j + 1]) j += 1;
        if (pattern[j + 1] == 0) return i - j;
    }
    return -1;
}

int GetNextJ(char ch, const char *pattern, int *next, int j) {
    while (j != -1 && ch - pattern[j + 1]) j = next[j];
    if (ch == pattern[j + 1]) j += 1;    
    return j;
}

int kmp_2(const char *text, const char *pattern) {
    int n = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * n);
    GetNext(pattern, next);
    for (int i = 0, j = -1; text[i]; i++) {
        j = GetNextJ(text[i], pattern, next, j);
        if (pattern[j + 1] == 0) return i - j;
    }
    return -1;
}
#define TEST(func, s1, s2) {\
    printf("%s(\"%s\", \"%s\") = %d\n", #func, s1, s2, func(s1, s2)); \
}

int main() {
    char s1[100], s2[100];
    while (cin >> s1 >> s2) {
        TEST(brute_force, s1, s2);
        TEST(kmp_1, s1, s2);
    }
    return 0;
}
