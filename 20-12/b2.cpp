/*************************************************************************
	> File Name: b2.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Wed 25 Nov 2020 11:34:24 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n, m;
    stack<int> s;
    queue<int> ctm, cha;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ctm.push(i);
    }
    /*
    cout << "顾客为 " ;
    for (int i = 0; i < n; i++) {
        cout << ctm.front() << " " ;
        ctm.pop();
    }
    */
    for (int i = 0; i < n; i++) {
        int t = 0;
        if (s.size() == 0) {
            cout << "barber is sleeping! " << endl << ctm.front() 
            << " weekup the barber  " << endl << ctm.front() << " getting a haircut " << endl;
            s.push(ctm.front());
            ctm.pop();
        }
        s.push(ctm.front());
        if (s.top() == 0) break;
        if (s.size() > 1) {
            cout << "barber is busy Please found a chair" << endl;
            cha.push(s.top());
            t = s.top();
            //cout << s.top() << " have found a chair " << endl;
            s.pop();
        }
        if (cha.size() <= m) {
            cout << t << " have found a chair " << endl;
        } else {
            cout << t << " quit!" << endl;
        }
        ctm.pop();
    }



}
