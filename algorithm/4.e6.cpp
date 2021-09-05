/*************************************************************************
	> File Name: 4.e6.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 07:17:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int s1, s2, s;

int main() {
    for (int i = 1; i <= 100; i++) {
        s += i;
        s1 += i * i;
    }
    cout <<  s * s - s1 << endl;
    return 0;
}
