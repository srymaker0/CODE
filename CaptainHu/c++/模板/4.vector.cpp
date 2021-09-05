#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    friend ostream &operator<<(ostream &out, const A &);

private:
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "Class A : " << a.x;
    return out;
}

namespace haizei {
template<typename T>                        //模板类vector
class vector {
public :
    vector(int n = 10);
    vector(const vector<T> &v);             //拷贝构造
    vector(vector<T> &&v);                   //移动构造

    T &operator[](int ind);                 //重载[]
    const T &operator[](int ind) const;     //处理const类型的        
    int size() const;                       //为了让const对象也能访问size方法

    void push_back(const T &);
    void push_back(T &&);         //可能传进来右值，分成两种情况可以提高效率

    ~vector();

private:
    int __size, __capacity;                   //size当前元素， capacity容量
    T *data;
};
    
template<typename T>
vector<T>::vector(int n) : __capacity(n), __size(0), data(nullptr) {
    data = (T *)malloc(sizeof(T) * __capacity);
    return ;
}

template<typename T>
vector<T>::vector(const vector<T> &v) : __size(v.__size), __capacity(__capacity) {
    data = (T *)malloc(sizeof(T) * __capacity);              //用malloc 避免T类型没有默认构造函数
    for (int i = 0; i < __size; i++) {                       //赋值运算符可能不会调用构造函数
        //显示的调用T类型的有参构造进行数据拷贝
        new(data + i) T(v.data[i]);                          //应采用原地构造的形式 不能用赋值运算符，容易出bug
    }
    return ;
}

template<typename T>                //移动构造， 传进来的还是一个vector对象，是一个左值          
vector<T>::vector(vector<T> &&v) : __size(v.__size), __capacity(v.__capacity), data(v.data) {
    v.data = nullptr;
    v.__size = 0;
    v.__capacity = 0;
}

template<typename T>
T &vector<T>::operator[](int ind) {
    return data[ind];
}

template<typename T>
const T &vector<T>::operator[](int ind) const {
    return data[ind];
}

template<typename T>
int vector<T>::size() const { return __size; }

template<typename T>
void vector<T>::push_back(const T &d) {
    new(data + __size) T(d);            //在最后一位 加d
    __size += 1;                        //元素个数加一
    return ;
}

template<typename T>
void vector<T>::push_back(T &&d) {
    new(data + __size) T(move(d));
    __size += 1;
    return ;
}

template<typename T>
vector<T>::~vector() {
    if (data) free(data);
    __size = 0;
    __capacity = 0;
    return ;
}

} // end of haizei

ostream &operator<<(ostream &out, const vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return out;
}

ostream &operator<<(ostream &out, const haizei::vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return out;
}

int main() {
    vector<A> v1;
    cout << v1.size() << endl;
    v1.push_back(123);
    v1.push_back(456);
    v1.push_back(789);
    haizei::vector<A> v2;
    cout << v2.size() << endl;
    v2.push_back(123);
    v2.push_back(456);
    v2.push_back(789);
    cout << v1 << endl;
    cout << v2 << endl;
    return 0;
}
