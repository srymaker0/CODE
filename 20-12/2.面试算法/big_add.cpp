/*************************************************************************
	> File Name: big_add.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Nov 2020 10:59:16 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int num1[105], num2[105], sum[105];
char s1[105], s2[105];

int main() {
    cin >> s1 >> s2;
    //
    num1[0] = strlen(s1);
    num2[0] = strlen(s2);
    //倒着存储 
    for (int i = 0, j = num1[0]; i < num1[0]; i++, j--) {
        num1[j] = s1[i] - '0';
    }
    for (int i = 0, j = num2[0]; i < num2[0]; i++, j--) {
        num2[j] = s2[i] - '0';
    }
    sum[0] = max(num1[0], num2[0]);
    for (int i = 1; i <= sum[0]; i++) {
        sum[i] = num1[i] + num2[i];
    }
    for (int i = 1; i <= sum[0]; i++) {
        if (sum[i] > 9) {
            sum[i + 1] += sum[i] / 10; //++sum[i + 1]
            sum[i] %= 10; // sum[i] -= 10
            if (i == sum[0]) {
                sum[0]++; //进位操作
            }
        }
    }
    for (int i = sum[0]; i > 0; i--) {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}
