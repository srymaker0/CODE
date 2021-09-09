/*************************************************************************
	> File Name: 1.queue.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 03 Apr 2021 02:04:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Node {
public :
    int val;
    Node *next, *pre;         //用链表去维护双端队列， 每个结点有前驱和后继
    Node(int val = 0, Node *next = nullptr, Node *pre = nullptr) : val(val), next(next), pre(pre) {}
    void insert_pre(Node *p) {                       //在当前节点前插入
        p->pre = this->pre;                          
        p->next = this;
        if (this->pre) this->pre->next = p;
        this->pre = p;
        return ;
    }
    void insert_next(Node *p) {
        p->pre = this;
        p->next = this->next;
        if (this->next) this->next->pre = p;
        this->next = p;
        return ;
    }
    void delete_pre() {
        if (this->pre == nullptr) return ;
        Node *p = this->pre;
        this->pre = p->pre;
        if (p->pre) p->pre->next = this;
        delete p;
        return ;
    }
    void delete_next() {
        if (this->next = nullptr) return ;
        Node *p = this->next;
        this->next = p->next;
        if (p->next) p->next->pre = this;
        delete p;
        return ;
    }
};

class Queue {
public :
    Node head, tail;
    int cnt;
    Queue() : cnt(0){
        head.next = &tail;
        head.pre = nullptr;
        tail.next = nullptr;
        tail.pre = &head;
    }
    void push_back(int val) {
        tail.insert_pre(new Node(val));
        cnt += 1;
        return ;
    }
    void push_front(int val) {
        head.insert_next(new Node(val));
        cnt += 1;
        return ;
    }
    int pop_back() {
        if (isEmpty()) return -1;
        int ret = tail.pre->val;
        tail.delete_pre();
        cnt -= 1;
        return ret;
    }
    int pop_front() {
        if (isEmpty()) return -1;
        int ret = head.next->val;
        head.delete_next();
        cnt -= 1;
        return ret;
    }
    int front() {
        return head.next->val;
    }
    int back() {
        return tail.pre->val;
    }
    bool isEmpty() {
        return head.next == &tail;
    }
    int size() {
        return cnt;
    }
};

class FrontMiddleBackQueue {
public:
    Queue q1, q2;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q1.push_front(val);
        //更新元素，偶数个元素两个队列元素相等  奇数个q1比q2多1个元素
        update();
        return ;
    }
    
    void pushMiddle(int val) {
        if (q1.size() > q2.size()) {      //若q1元素个数>q2，
            q2.push_front(q1.back());     //则给q2一个元素(q1的尾部元素)
            q1.pop_back();                //将q1的尾部元素销毁
        }
        q1.push_back(val);                //将val插入到q1尾部
        return ;
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        update();
        return ;
    }
    
    int popFront() {
        if (isEmpty()) return -1;
        int ret = q1.pop_front();
        update();
        return ret;
    }

    int popMiddle() {
        if (isEmpty()) return -1;
        int ret = q1.pop_back();          //根据题意 pop的一定是q1的尾部元素
        update();
        return ret;
    }
    
    int popBack() {
        if (isEmpty()) return -1;
        int ret;
        if (q2.isEmpty()) {
            ret = q1.pop_back();
        } else {
            ret = q2.pop_back();
        }
        update();
        return ret;
    }
    bool isEmpty() {
        return q1.size() == 0;
    }
    void update() {
        if (q1.size() < q2.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        if (q1.size() == q2.size() + 2) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        return ;
    }
};
