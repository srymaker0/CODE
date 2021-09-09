/*************************************************************************
	> File Name: 1.hash_table.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 10 Jul 2021 04:13:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node(string data = "", Node *next = nullptr) : data(), next(nullptr) {}
    string data;
    Node *next;
    void insert(Node *node) {
        node->next = this->next;
        this->next = node;
        return ;
    }
};

class HashTable {
public:
    HashTable(int n = 100) : data(n),  cnt(0) {}
    // 插入元素
    void insert(string s) {
        int ind = hash_func(s) % data.size();       // 1、计算哈希值 
        recalc_ind(ind, s);                         // 2、冲突处理
        // 3、插入元素
        Node *p = &data[ind];                               // 指向当前地址
        while (p->next && p->next->data != s) p = p->next;  // 找到指向最后一个元素的节点
        if (p->next == nullptr) {                           // 说明没有存放过当前元素
            p->insert(new Node(s));                         // 插入到p节点的后面
            cnt += 1;
            if (cnt > data.size() * 3) expand();            // 装填因子，说明每个位置上有3个节点，需要扩容
        }
        return ;
    }
    // 查找元素
    bool find(string s) {
        int ind = hash_func(s) % data.size();       // 获取这个字符串的哈希值
        recalc_ind(ind, s);                         // 冲突处理 重获下标
        Node *p = data[ind].next;
        while (p && p->data != s) p = p->next;      // 遍历节点
        return p != nullptr;                        // 若不为空 则一定存在s元素
    }
private:
    int cnt;
    vector<Node> data;    
    // 扩容
    void expand() {
        int n = data.size() * 2;                    // 原来的两倍容量 
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            Node *p = data[i].next;
            while (p) {
                h.insert(p->data);
                p = p->next;
            }
        }
        *this = h;                                  // 将当前哈希表变为扩容后的
        return ;
    }
    // BKDR处理法，将字符串转化为整形
    int hash_func(string &s) {
        int seed = 131, hash = 0;                   // seed是一个素数
        for (int i = 0; s[i]; i++) {
            hash = hash * seed + s[i];
        }
        return hash & 0x7fffffff;                   // 使hash值一直是正数
    }
    void recalc_ind(int &ind, string &s) {
        return ;
    }
};

int main() {
    int op;
    string s;
    HashTable h;
    while (cin >> op >> s) {
        switch (op) {
            case 1: h.insert(s); break;
            case 2: cout << h.find(s) << endl; break;
        }
    }
    return 0;
}
