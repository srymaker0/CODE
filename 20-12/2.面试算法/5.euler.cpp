/*************************************************************************
	> File Name: euler5.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Oct 2020 06:59:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int sum = 0, psum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
        psum += i * i;
    }
    cout << sum * sum - psum << endl;
    return 0;
}
