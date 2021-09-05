/*************************************************************************
	> File Name: 04.deep_copy.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Feb 2021 03:51:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
public :
    Array(int n = 10) {
        this->n = n;
        data = new int[n];
    }
    Array(const Array &a) {                         //深拷贝，重新给b开辟了空间
        this->n = a.n;
        this->data = new int[this->n];
        for (int i = 0; i < this->n; i++) {
            this->data[i] = a.data[i];
        }
    }
    size_t size() const { return this->n; }
    int &operator[](int ind) {                      //写了两个[]重载 分别对应的是non-const和const
        if (ind < 0 || ind >= n) return end;
        return data[ind];
    }
    const int &operator[](int ind) const{
        if (ind < 0 || ind >= n) return end;
        return data[ind];
    }
private :
    int *data, end;
    size_t n;
};

ostream &operator<<(ostream &out, const Array &a) {
    out << "Array(" << &a << ") : ";
    for (int i = 0; i < a.size(); i++) {
        i && out << " ";
        out << a[i];
    }
    return out;
}

int main() {
    Array a;
    for (int i = 0; i < a.size(); i++) {
        a[i] = rand() % 100;
    }
    cout << a << endl;
    Array b = a;
    cout << b << endl;
    b[1] = 11111;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
