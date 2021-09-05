/*************************************************************************
	> File Name: 6.struct_program.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 11:14:04 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int a, b, n, cnt = 0;
    /*time(0) 是一个可变值  这是设置了一个随机数种子 可以产生不同的随机数
     * 但本质上cpu并不是真的提供随机数
    **/
    srand(time(0));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int val = rand() % 100;//取0~99的随机整数
        cnt += (val & 1); //进行一个位与运算 记录奇数的个数 val & 1 等价于 val % 2
        i && printf(" ");
        printf("%d", val);
    }
    printf("\n");
    printf("odd num : %d\n", cnt);
    return 0;
    scanf("%d%d", &a, &b);
    /*if(a - b){
        printf("not equal!\n");
    }else{
        print("equal\n");
    }
    对于if else 可以用三目运算符
    */
    printf("%s\n", (a - b) ? "not equal" : "equal");
    //这里比较了++运算符  && 和 || 都有自己的原则 一旦第一个条件分别为假和真
    //后面不管是什么都不运算
    a = 0, b = 0;
    if((a++) && (b++)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    if((a++) || (b++)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
