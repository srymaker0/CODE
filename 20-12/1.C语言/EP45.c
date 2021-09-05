/*************************************************************************
	> File Name: EP45.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Oct 2020 02:43:05 PM CST
 ************************************************************************/

#include<stdio.h>
typedef long long ll;

ll Triangle(ll n){
    return n * (n + 1) / 2;
}

ll Pentagonal(ll n){
    return n * (3 * n - 1) / 2;
}

ll Hexagonal(ll n){
    return n * (2 * n - 1);
}

/*
//基本的二分法查找 只适用于单调递增的一串数据 *arr是一个数组
ll binary_search(ll *arr, ll n, ll x){
    ll head = 0, tail = n - 1, mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(arr(mid) == x) return mid;
        if(arr(mid) < x)head = mid + 1;
        else tail = mid - 1;
    }
    return -1;//这里只是一个程序设计技巧 代表这段区间内没有x的值
}
*/

//我们的二分查找不需要数组， 需要是一种映射关系 *arr是函数指针
ll binary_search(ll (*arr)(ll), ll n, ll x){
    ll head = 1, tail = n, mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(arr(mid) == x) return mid;
        if(arr(mid) < x)head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main(){
    ll n = 143;
    while(1){
        n += 1;
        ll temp = Hexagonal(n);
        if(binary_search(Pentagonal, temp, temp) == -1)continue;//continue 结束本次循环
        printf("%lld\n", temp);
        break;
    }
    return 0;
}

/*
int main(){
    int n = 285;
    while(1){
        n += 1;
        ll temp = Triangle(n);
        if(binary_search(Pentagonal, temp, temp) != -1){
            if(binary_search(Hexagonal, temp, temp) != -1){
                printf("%d\n", temp);
                break;
            }
        }
    }
    return 0;
}
*/




