/*************************************************************************
	> File Name: 21.ip.c
	> Author: 
	> Mail: 
	> Created Time: Fri 30 Oct 2020 11:46:15 AM CST
 ************************************************************************/
#include <stdio.h>

//将IP地址转换成整数

union IP {
    //匿名结构体
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
    unsigned int num;
};

//判断是否是小端机
int is_little() {
    static int num = 1;
    return ((char *)(&num))[0];
}

int main() {
    printf("%d\n", is_little());
    union IP p;
    char str[100] = {0};
    int arr[4];
    while (~scanf("%s", str)) {
        //sscanf是将str里的字符输入到arr里面 从字符串str中读入一个值
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        /*
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
        */
        //因为是小端机 我们要把数据倒过来存储
        p.ip.a1 = arr[3];
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];
        //因为num 与 struct是一个共用体 我一次取4个字节的数相当于取了4个char num与char占用一个空间
        printf("%u\n", p.num);
    }
    return 0;
}
