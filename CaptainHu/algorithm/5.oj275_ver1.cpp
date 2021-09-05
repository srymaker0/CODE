/*************************************************************************
	> File Name: 5.oj275_ver1.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 22 Jan 2021 08:59:29 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
// MAX_N 数据范围 
#define MAX_N 1000000  
//#define P 100007
#define P 100019
#define base 13
long long H[MAX_N + 5];
long long K[MAX_N + 5];  //K[0] 表示base^0 % P
long long inv[P]; //表示从(0到P-1) % P的逆元

char s[MAX_N + 5];

void init() {
    inv[1] = 1;
    for (long long i = 2; i < P; i++) {
        inv[i] = (P - P / i) * inv[P % i] % P;   //初始化逆元数组
    }
    K[0] = 1;   
    for (long long i = 1; i <= MAX_N; i++) {
        K[i] = (K[i - 1] * base) % P;            //初始化base数组
    }
    H[0] = 0;
    for (long long i = 1; s[i]; i++) {           //初始化H数组 (字符串*base^i)%p    
        H[i] = (H[i - 1] + K[i] * s[i]) % P;     //H数组相当于前缀和 这样可快速求得 
    }                                            //此时的H数组相当于把源字符串都映射成了一个哈希值
    return ;
}

long long getH(long long l, long long r) {
    return ((H[r] - H[l - 1]) % P * inv[K[l]] % P + P) % P;//l-1是因为前缀和要减去左区间前一个位置的和
}

long long isSame(long long i, long long j, long long n) {
    for (long long k = 0; k < n; k++) {
        if (s[i + k] - s[j + k]) return false;
    }
    return true;
}

int main() {
    scanf("%s", s + 1); //字符串从第一位开始读入
    long long m, l1, l2, r1, r2;
    init();
    scanf("%lld", &m);   //读入询问次数
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        long long val1 = getH(l1, r1);      //获取相关区间的H值
        long long val2 = getH(l2, r2);
        long long n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;  //n1 n2表示两个字符串长度
        if (n1 - n2 && val1 - val2) {                 
            printf("No\n");
        } else {                                       //因为哈希值相等有可能两个字符串还是失配
            if (isSame(l1, l2, n1)) {                  //所以还要进行一轮判断 只是通过哈希值比较
                printf("Yes\n");                       //但是如果两个字符串不一样 则不可能进入到
            } else {                                   //else判断里面 
                printf("No\n");    
            }
        }
    }
    return 0;
}
