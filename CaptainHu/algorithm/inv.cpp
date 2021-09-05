/*************************************************************************
	> File Name: inv.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 22 Jan 2021 04:58:46 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int inv[7] = {0};

int main() {
    inv[1] = 1; // 1的逆元一定是1 0的逆元是0
    for (int i = 2; i < 7; i++) {
        //inv[i] = ((-(7 / i) * inv[7 % i]) % 7 + 7) % 7; //inv[i] 保存的是i的逆元
        inv[i] = (7 - 7 / i) * inv[7 % i] % 7; //inv[i] 保存的是i的逆元
        cout << i << " : " << inv[i] << endl;
    }
    return 0;
}
