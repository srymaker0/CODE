/*************************************************************************
	> File Name: mul.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Dec 2020 06:51:07 PM CST
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

char num1[1005], num2[1005];
int n1[1005], n2[1005], ans[1005];


int main() {
    cin >> num1 >> num2;
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    ans[0] = n1[0] + n2[0] - 1; //答案最短长度
    for (int i = 1, j = n1[0] - 1; i <= n1[0]; i++, j--) {
        n1[i] = num1[j] - '0';
    }
    for (int i = 1, j = n2[0] - 1; i <= n2[0]; i++, j--) {
        n2[i] = num2[j] - '0';
    }
    for (int i = 1; i <= n1[0]; i++) {
        for (int j = 1; j <= n2[0]; j++) {
            ans[i + j - 1] += n1[i] * n2[j];
        }
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) {
                ans[0]++;
            }
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}


int main() {
    cin >> num1 >> num2;
    

}

