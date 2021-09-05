/*************************************************************************
	> File Name: 5.oj40爬楼梯.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 04 Feb 2021 03:37:46 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class BigInt : public vector<int> {
public :
    BigInt() {
        push_back(0);
    }
    BigInt(int x) {
        push_back(x);
        process_digit();
    }
    void operator+=(const BigInt &num) {
        for (int i = 0; i < num.size(); i++) {
            if (i == size()) push_back(num[i]);
            else at(i) += num[i];
        }
        process_digit();
        return ;
    }
    BigInt operator+(const BigInt &num) {
        BigInt ret(*this);
        ret += num;
        return ret;
    }
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[505];

ostream &operator<<(ostream &out, const BigInt &num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        out << num[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    f[0] = 1, f[1] = 0, f[2] = 1, f[3] = 1;
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
    return 0;
}
