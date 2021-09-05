/*************************************************************************
	> File Name: 2.test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Oct 2020 02:23:53 PM CST
 ************************************************************************/


#include<stdio.h>

int main(){
    char str[100] = {0};
    while(scanf("%[^\n]s", str) != EOF){
        getchar();
        printf(" has %d chars!\n", printf("%s", str));
    }

    return 0;
}


