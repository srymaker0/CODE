/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:25:49 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
    vector<int> v;
    for (int i = 105; i <= 110; i++) {
        v.push_back(i);
        cout << v.size() << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    */
    vector<vector<int> > v;
    v.push_back(vector<int>());
    for (int i =66; i <= 70; i++) {
        v[0].push_back(i);
    }
    v.push_back(vector<int>(5, 0));
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v.push_back(v2);
    v.push_back(vector<int>(10, 0));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
