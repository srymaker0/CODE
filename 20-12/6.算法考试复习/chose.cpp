/*************************************************************************
	> File Name: chose.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sun 29 Nov 2020 09:56:21 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct person {
    string name;
    char num[10], cos[25];
    int cnt;
};

int n, m;
person stu[105];

void func() {
    for (int i = 0; i < n; i++) {
        if (stu[i].cos)
    }

}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].num >> stu[i].name >> stu[i].cnt >> stu[i].cos;
    }
    cout << stu[0].num << endl << stu[0].name << endl;
    return 0;
}
