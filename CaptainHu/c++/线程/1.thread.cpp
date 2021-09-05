/*************************************************************************
	> File Name: 1.thread.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 20 Mar 2021 07:38:06 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <functional>
using namespace std;


void add_one(int &x) {
    cout << "add_one function" << endl;
    x += 1;
    return ;
}

//与线程池的实现强相关
class Task {
public :
    template<typename FUNCTION, typename ...ARGS>
    Task(FUNCTION &&f, ARGS ...args) {
        cout << "Task constructor" << endl;
        //参数和函数之间的绑定 bind返回的是一个可调用对象
        this->f = bind(f, forward<ARGS>(args)...);  //forward向前传递的参数类型变为左值引用 
    }
    void run() {
        f();
    }
private :
    function<void()> f;      //可以指向任意可调用对象的对象
};

int main() {
    int n = 8;
    thread t1(add_one, ref(n));
    t1.join();
    Task t2(add_one, ref(n));
    t2.run();
    t2.run();
    t2.run();
    cout << "hello world" << endl;
    cout << n << endl;
    return 0;
}
