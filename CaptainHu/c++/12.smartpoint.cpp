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
    A *operator->();     //重载间接引用
    A &operator*();
    shared_ptr &operator=(const shared_ptr &);
private :
    void decrease_by_one();
    void increase_by_one();
    int *cnt;     //引用计数
    A *obj;       //A类指针
};

shared_ptr::shared_ptr() :obj(nullptr), cnt(nullptr) {}                //赋初值
shared_ptr::shared_ptr(A *obj) : obj(obj), cnt(new int(1)) {}          //计数加1，因为是指针，要开辟1个整型数据空间
shared_ptr::shared_ptr(const shared_ptr &p) : obj(p.obj), cnt(p.cnt) { increase_by_one(); }    //拷贝
A *shared_ptr::operator->() {return obj;}   //返回的是地址
A &shared_ptr::operator*() {return *obj;}   //返回的是指向的对象
shared_ptr::~shared_ptr() {
    this->decrease_by_one();
    this->obj = nullptr;
    this->cnt = nullptr;
}

void shared_ptr::decrease_by_one() {
    if (this->cnt != nullptr) {
        *(this->cnt) -= 1;
        if (*(this->cnt) == 0) {
            delete this->obj;
            delete this->cnt;
        }
    }    
    return ;
}

void shared_ptr::increase_by_one() {
    if (cnt != nullptr) {
        cnt[0] += 1;               //cnt[0]与*cnt等价
    }    
    return ;
}    

shared_ptr &shared_ptr::operator=(const shared_ptr &p) {     
    if (this->obj != p.obj) {               //若两个对象不相等，智能指针指向额外的对象则
        decrease_by_one();                  //计数器减1
        obj = p.obj;                        //拷贝
        cnt = p.cnt;
        increase_by_one();                  //若p指向对象 则将本对象的计数器加1 
    }    
    return *this;                           //返回对象本身
}

int shared_ptr::use_count() {return cnt ? *cnt : 0 ;}    //输出cnt的值


}

int main() {
    haizei::A *p1 = new haizei::A();
    p1 = nullptr;
    haizei::shared_ptr p2(new haizei::A());
    cout << p2.use_count() << endl;
    haizei::shared_ptr p3 = p2;
    p2->x = 123; p2->y = 456;
    (*p2).x = 456;
    cout << p3.use_count() << endl;
    cout << p2.use_count() << endl;
    p2 = nullptr;
    cout << p2.use_count() << endl;
    cout << p3.use_count() << endl;
    p2 = p3;
    cout << p3.use_count() << endl;
    return 0;
}
