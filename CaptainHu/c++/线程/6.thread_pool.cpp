/*************************************************************************
	> File Name: 11.thread_pool.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <vector>
#include <thread>
#include <queue>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <mutex>                // 互斥锁
#include <condition_variable>   // 条件信号量

namespace haizei {

// 任务类，将参数和函数绑定
class Task {
public :
    template<typename FUNCTION, typename ...ARGS>
    Task(FUNCTION &&func, ARGS ...args);
    void run();

private:
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5);                              // 默认有5个线程
    template<typename FUNCTION, typename ...ARGS>
    void addOneTask(FUNCTION &&, ARGS...);              // 往线程池中添加任务
    void stop();

private:
    std::vector<std::thread *> threads;
    std::queue<Task *> tasks;                               // 可优化，改成优先队列
    std::unordered_map<std::thread::id, bool> running;      // 哈希表存线程的运行状态
    std::mutex m_mutex;                                     // C++中互斥锁
    std::condition_variable m_cond;                         // 条件信号量

    void worker_thread();                               // 入口函数 
    Task *getOneTask();                                 // 从任务队列中获取任务
    void stop_thread();                                 // 毒药任务
};

template<typename FUNCTION, typename ...ARGS>
Task::Task(FUNCTION &&func, ARGS ...args) {
    this->func = std::bind(func, std::forward<ARGS>(args)...);
}

void Task::run() {
    std::cout << "Task run : " << std::endl;
    func();
    return ;
}

// 线程池中新建线程对象
ThreadPool::ThreadPool(int n) {
    for (int i = 0; i < n; i++) {
        //worker_thread 为线程对象的入口函数， this是这个函数的参数(在成员函数中被编译器隐藏的) 
        threads.push_back(new std::thread(&ThreadPool::worker_thread, this));
    }
    return ;
}

// 入口函数，成员函数至少有一个参数->this
void ThreadPool::worker_thread() {
    std::thread::id id = std::this_thread::get_id();      // 获得线程的id
    running[id] = true;
    while (running[id]) {                           // 死循环
        Task *t = this->getOneTask();               // 取任务
        t->run();                                   // 执行任务
        delete t;                                   // 销毁任务    
    }
    return ;
}

template<typename FUNCTION, typename ...ARGS>
void ThreadPool::addOneTask(FUNCTION &&func, ARGS... args) {
    std::unique_lock<std::mutex> lock(m_mutex);                 // 抢占互斥锁，线程抢队列这个资源 
    tasks.push(new Task(func, std::forward<ARGS>(args)...));    // 把相关的任务push到队列
    m_cond.notify_one();                                        // 通知其它线程我们的队列中有任务了(队列非空)
    return ;
}

// 线程获取任务
Task *ThreadPool::getOneTask() {
    // lock是一个对象，当构造完成后自动的抢占了锁，析构时自动的释放锁
    // 这只是其中一种方式抢占锁，好处是可以自动的抢占和释放
    std::unique_lock<std::mutex> lock(m_mutex);     // 操作任务队列之前，抢占互斥锁
    // 若队列为空
    while (tasks.empty()) {
        // wait一个条件->等待任务队列非空(条件)，这种条件是逻辑上的，人为定义的
        m_cond.wait(lock);                          // 传入lock为了让抢占互斥锁的线程释放锁，让其它线程可以获取任务
    }
    Task *t = tasks.front();                        // 取队列中的任务
    tasks.pop();                                    // 取完后弹出任务
    return t;                                       // 返回取出任务的地址    
}

// 毒药任务，用与结束线程池中的线程
void ThreadPool::stop_thread() {
    std::thread::id id = std::this_thread::get_id();  // this_thread 线程池中的id?
    running[id] = false;
    return ;
}

// 停掉线程池——等到线程池的任务都结束了，再结束线程池
void ThreadPool::stop() {
    for (int i = 0; i < threads.size(); i++) {
        this->addOneTask(&ThreadPool::stop_thread, this);      // stop_thread是成员函数，至少有this参数，还能访问running
    }
    for (auto t : threads) {
        t->join();                   // 等待每一个线程结束
    }
    return ;                         // 当所有线程结束后，return
}

} // end of haizei

void func(int a, int b, int c) {
    std::cout << "func id : " << a << ", " << a + b + c << std::endl;
    return ;
}

int main() {
    haizei::ThreadPool tp;
    for (int i = 0; i < 100; i++) {
        tp.addOneTask(func, i, 2 * i, 3 * i);
    }
    tp.stop();           
    return 0;
}
