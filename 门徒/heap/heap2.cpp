/*************************************************************************
	> File Name: heap2.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 09 May 2021 10:04:00 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

template<typename T>
class Heap : public vector<T> {
public :
    template<typename Func_T>
    Heap(Func_T cmp) : cmp(cmp) {}
    void push(const T &a) {
        this->push_back(a);      //this表示vector
        push_heap(this->begin(), this->end(), cmp);    //algorithm头文件
        return ;
    }
    void pop() {
        pop_heap(this->begin(), this->end(), cmp);
        this->pop_back();
        return ;
    }
    T &top() { return this->at(0); }
private :
    function<bool(T, T)> cmp;         //cmp可调用对象 返回值是bool，参数为两个T类型
};

int main() {
    Heap<int> h1{less<int>()};    //大顶堆   越小优先级越小 所以是大顶堆
    Heap<int> h2{greater<int>()}; //小顶堆   越大优先级越小 所以是小顶堆
    h1.push(3); h1.push(2); h1.push(4); h1.push(1);
    h2.push(3); h2.push(2); h2.push(4); h2.push(1);
    while (h1.size()) {
        cout << h1.top() << " ";
        h1.pop();
    }
    cout << endl;
    while (h2.size()) {
        cout << h2.top() << " ";
        h2.pop();
    }
    cout << endl;
    return 0;
}
