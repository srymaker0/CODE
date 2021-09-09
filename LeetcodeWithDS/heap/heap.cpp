/*************************************************************************
	> File Name: heap.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 08 May 2021 11:37:12 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
int data[MAX_N], cnt = 0;               //用数组实现

int top() { return data[0]; }

int size() { return cnt; }

//插入调整
void shift_up(int ind) {
    while (ind && data[ind] > data[(ind - 1) / 2]) {
        swap(data[ind], data[(ind - 1) / 2]);
        ind = (ind - 1) / 2;
    }
    return ;
}

//删除调整
void shift_down(int ind) {
    int n = cnt - 1;
    while (ind * 2 + 1 < n) {
        int temp = ind;
        if (data[temp] < data[ind * 2 + 1]) temp = ind * 2 + 1;
        if (ind * 2 + 2 <= n && data[temp] < data[ind * 2 + 2]) temp = ind * 2 + 2;
        if (temp == ind) break;
        swap(data[temp], data[ind]);
        ind = temp;
    }
    return ;
}

void output(int n) {
    printf("heap : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return ;
}

//插入
void push(int x) {
    data[cnt] = x;
    cnt += 1;
    shift_up(cnt - 1);
    return ;
} 

void pop() {
    if (size() == 0) return ;
    swap(data[0], data[cnt - 1]);
    cnt -= 1;
    shift_down(0);
    return ;
}

int main() {
    int op, val;
    int max_n = 0;
    while (cin >> op) {
        switch (op) {
            case 0: {
                cin >> val;
                printf("push %d to heap\n", val);
                push(val);
            } break;
            case 1: {
                printf("pop %d from heap\n", top());
                pop();
            } break;
            case 2: {
                output(max_n);
            } break;
        }
        max_n = max(cnt, max_n);
        output(cnt);
    }
    return 0;
}
