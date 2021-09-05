/*************************************************************************
	> File Name: 3.nullptr.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 03:26:28 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//nullptr 
//NULL
//
void func(int x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}

void func(int *x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}

int main() {
    //cout << NULL << endl;
    //cout << nullptr << endl;
    
    if (NULL) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    if (nullptr) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    func(nullptr);
    //func(NULL);
    return 0;
}
