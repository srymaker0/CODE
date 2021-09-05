/*************************************************************************
	> File Name: 5.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 03:05:37 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        while(i % 2 == 0){
            i /= 2;
        }
        while(i % 3 == 0){
            i /= 3;
        }
        while(i % 5 == 0){
            i /= 5;
        }
        printf("%d", i);
    }
    return 0;
}
