/*************************************************************************
	> File Name: 4.oj38兔子繁殖.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 04 Feb 2021 02:23:15 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct BigInt : vector<int> {
    BigInt(int x) {
        push_back(x);
        normal();
    }
    BigInt operator+(const BigInt &b) {
        BigInt ret = (*this);
        for (int i = 0; i < b.size(); i++) {
            if (i < ret.size()) {
                ret[i] += b[i];
            } else {
                ret.push_back(b[i]);
            }
        }
        ret.normal();
        return ret;
    }
    void normal() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    BigInt a = 1, b = 1, c = 0;
    cin >> n;
    while (n--) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
    return 0;
}


