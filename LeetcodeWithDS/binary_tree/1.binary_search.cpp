/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 01 Apr 2021 08:33:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) return 0;
    int MAX_N = atoi(argv[1]);
    Node *root = NULL;
    for (int i = 0; i < MAX_N; i++) {
        root = random_insert(root);
    }


    return 0;
}
