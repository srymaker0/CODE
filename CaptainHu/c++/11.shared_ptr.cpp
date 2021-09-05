/*************************************************************************
	> File Name: 11.shared_ptr.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 06 Mar 2021 03:00:14 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

namespace haizei {

class A {
public :
    A() {
        cout << "default constructor " << endl;
    }
    int x, y;
    ~A() {
        cout << "destructor" << endl;
    }
};

class shared_ptr {
public :
    shared_ptr();
    shared_ptr(A *);
    shared_ptr(const shared_ptr &);
    ~shared_ptr();
    int use_count();
private :
    int *cnt;
    A *obj;
};
shared_ptr::shared_ptr() :obj(nullptr), cnt(nullptr) {}
shared_ptr::shared_ptr(A *obj) : obj(obj), cnt(new int(1)) {}
shared_ptr::shared_ptr(const shared_ptr &p) : obj(p.obj), cnt(p.cnt) { *p.cnt += 1; }

    ~shared_ptr::~shared_ptr() {
    if (cnt != nullptr) {
        *cnt -= 1;
        if (*cnt == 0) delete obj;
        obj = nullptr;
        cnt = nullptr;
    }
}

}
int main() {
    A *p1 = new A();
    p1 = nullptr;
    shared_ptr<A> p2(new A());
    cout << p2.use_count() << endl;
    shared_ptr<A> p3 = p2;
    p2->x = 123; p2->y = 456;
    cout << p2.use_count() << endl;
    p2 = nullptr;
    cout << p3.use_count() << endl;
    return 0;
}
