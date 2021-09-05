/*************************************************************************
	> File Name: rand_haffman.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 06 Jan 2021 07:45:24 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int arr[26], sum = 0;
    for (int i = 0; i < 26; i++) {
        arr[i] = rand() % 1000;
        sum += arr[i];
    }
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %lf\n", i + 'A', 1.0 * arr[i] / sum);
    }

    return 0;
}

