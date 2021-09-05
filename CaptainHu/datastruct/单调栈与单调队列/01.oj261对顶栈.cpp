/*************************************************************************
	> File Name: 01.oj261对顶栈.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 05 Feb 2021 08:57:00 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <cinttypes>
using namespace std;

class NewStruct {
public:
    NewStruct() {
        sum[0] = 0;
        ans[0] = INT64_MIN;
    }
    void insert(long long x) {
        s1.push(x);
        long long ind = s1.size();
        long long val1 = x + sum[ind - 1];
        long long val2 = max(ans[ind - 1], val1);
        sum[ind] = val1;
        ans[ind] = val2;
        return ;
    }
    void del() {
        if (s1.empty()) return ;
        s1.pop();
        return ;
    }
    void move_left() {
        if (s1.empty()) return ;
        s2.push(s1.top());
        del();
        return ;
    }
    void move_right() {
        if (s2.empty()) return ;
        insert(s2.top());
        s2.pop();
        return ;
    }
    long long query(long long k) {
        if (k > s1.size() + s2.size()) return ans[s1.size() + s2.size()];
        return ans[k];
    }
private:
    stack<long long> s1, s2;
    long long sum[1005];
    long long ans[1005];
};


int main() {
    long long N;
    cin >> N;
    string op;
    long long val;
    NewStruct s;
    for (long long i = 0; i < N; i++) {
        cin >> op;
        switch(op[0]) {
            case 'I': cin >> val; s.insert(val); break;
            case 'D': s.del(); break;
            case 'L': s.move_left(); break;
            case 'R': s.move_right(); break;
            case 'Q': {
                cin >> val;
                cout << s.query(val) << endl;
            }
        }
    }
    
    return 0;
}
