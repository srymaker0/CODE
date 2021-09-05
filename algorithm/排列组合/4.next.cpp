/*************************************************************************
	> File Name: 4.next.cpp
	> Author:Yj_Z 
	> Mail: 
	> Created Time: Tue 19 Jan 2021 08:36:20 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

void p() {
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    do {
        p();
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
