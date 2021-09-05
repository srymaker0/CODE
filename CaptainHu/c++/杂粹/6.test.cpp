/*************************************************************************
	> File Name: 6.test.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 15 Mar 2021 10:26:40 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int y = 123;
    int &&x = y;
    cout << x << endl;
    return 0;
}
