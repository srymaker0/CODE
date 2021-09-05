/*************************************************************************
	> File Name: fib.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Oct 2020 08:14:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long num[50];

int f(int n) {
    if (n == 1 || n == 2 ) return 1;
    if (num[n]) return num[n];
    return num[n] = f(n - 1) + f(n - 2);

}


int main() {
   for (int i = 1; i <= 40; i++ ) {
    cout << i << " : " << f(i) << endl;
   }
    return 0;
}
