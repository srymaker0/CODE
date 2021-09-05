/*************************************************************************
	> File Name: 3.function.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 28 Mar 2021 02:32:59 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

namespace haizei {

template<typename T, typename ...ARGS>
class base {
public :
    virtual T run(ARGS...) = 0;
    virtual base<T, ARGS...> *getCopy() = 0;
    virtual ~base() {}
};

//函数指针
template<typename T, typename ...ARGS>
class normal_func : public base<T, ARGS...> {
public :
    typedef T (*FUNC_T)(ARGS...);
    normal_func(FUNC_T func) : func(func) {}
    T run(ARGS ...args) override {
        return func(forward<ARGS>(args)...);
    }
    base<T, ARGS...> *getCopy() override {
        return new normal_func(func);
    }
private :
    FUNC_T func;
};

//可调用对象
template<typename C, typename T, typename ...ARGS>
class functor : public base<T, ARGS...> {
public :
    functor(C obj) : obj(obj) {}
    T run(ARGS ...args) override {
        return obj(forward<ARGS>(args)...);
    }
    base<T, ARGS...> *getCopy() override {
        return new functor(obj);
    }
private :
    C obj;
};

template<typename T, typename ...ARGS> class function;     //原模版声明
template<typename T, typename ...ARGS>    //这是模版的偏特化形式
class function<T(ARGS...)> {
public :
    function(T (*ptr)(ARGS...)) : fptr(new normal_func<T, ARGS...>(ptr)) {}
    template<typename C>
    function(C object) : fptr(new functor<C, T, ARGS...>(object)) {}
    function(const function<T(ARGS...)> &obj) {
        this->fptr = obj.fptr->getCopy();
    } // 拷贝构造
    function(function<T(ARGS...)> &&obj) : fptr(obj.fptr) {
        obj.fptr = nullptr;
    } // 移动构造

    function &operator=(const function &obj) {
        if (this == &obj) return *this;
        if (this->fptr) delete this->fptr;
        this->fptr = obj.fptr->getCopy();
        return *this;
    } // 左值赋值运算符
    function &operator=(function &&obj) {
        if (this == &obj) return *this;
        this->fptr = obj.fptr;
        obj.fptr = nullptr;
        return *this;
    }

    T operator()(ARGS ...args) {
        return fptr->run(forward<ARGS>(args)...);
    }
    
    ~function() {
        if (fptr != nullptr) delete fptr;
        fptr = nullptr;
    }
private :
    base<T, ARGS...> *fptr;
};

} //end of haizei

void func(int a, int b) {
    cout << "normal function" << endl;
    return ;
}

class ADD_FUNC {
public :
    ADD_FUNC() : x(0) {}
    void operator()(int a, int b) {
        x += a + b;
        cout << "class object\n" << x << endl;
        return ;
    }
    int x;
};

int main() {
    ADD_FUNC add;
    function<void(int, int)> F1 = func;
    function<void(int, int)> F2 = add;
    F2(5, 6);
    haizei::function<void(int, int)> f1 = func;
    haizei::function<void(int, int)> f2 = add; 
    f2(5, 6);
    haizei::function<void(int, int)> f3(f2);
    f3(7, 8);
    f3 = f1;
    f3(7, 8);
    return 0;
}

