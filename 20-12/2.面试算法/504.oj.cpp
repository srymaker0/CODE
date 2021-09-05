/*************************************************************************
	> File Name: 504.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Nov 2020 06:18:46 PM CSTi
    > 面试会考这种类型的题
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string str;
int n;

int main() {
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') {
            f = 1;
        }
        if (f == 1) {
            cout << str[i];   
        }
    }
    cout << endl;
    return 0;
}
