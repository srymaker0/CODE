/*************************************************************************
	> File Name: 9.hash.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 27 Mar 2021 01:08:34 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//拉链法
class Node {
public :
    Node() = default;
    Node(string, int, Node *);
    string key();
    int value;                      //设置为公有，数组下标
    Node *next();
    void set_next(Node *);
    void insert(Node *);
    void erase_next();

private:
    string __key;                   //当前存储的字符串
    Node *__next;                   //下一个结点
};

class HashTable {
public :
    typedef function<int(string)> HASH_FUNC_T;              //可调用对象，传入一个字符串，返回值是int
    HashTable(HASH_FUNC_T hash_func, int size);             //传入hash函数
    bool insert(string, int);                               //插入
    bool erase(string);                                     
    bool find(string);
    int capacity();
    int &operator[](string);                                //返回的是value项

private:
    Node *__insert(string, int);
    Node *__find(string);
    void __expand();                                        //扩容
    int __size, data_cnt;                                   //哈希表中当前存储数据的总数量
    vector<Node> data;
    HASH_FUNC_T hash_func;                                  //哈希函数
};

Node::Node(string key, int value = 0, Node *next = nullptr) 
: __key(key), value(value), __next(next) {}
string Node::key() { return this->__key; }
Node *Node::next() { return this->__next; }
void Node::set_next(Node *next) { this->__next = next; }
void Node::insert(Node *p) { 
    p->__next = this->__next; 
    this->__next = p;
    return ;
}
void Node::erase_next() { 
    if (this->__next == nullptr) return ;
    Node *q = this->__next; 
    this->__next = this->__next->__next;
    delete q;
    return ;
}

HashTable::HashTable(HASH_FUNC_T hash_func, int size = 2) 
: __size(size), data(__size), hash_func(hash_func), data_cnt(0) {}

int HashTable::capacity() { return this->__size; }
bool HashTable::insert(string key, int value = 0) {
    if (find(key)) return false;
    return __insert(key, value);
}
Node *HashTable::__insert(string key, int value = 0) {
    if (data_cnt >= __size) __expand();
    int h = hash_func(key) % __size;
    data[h].insert(new Node(key, value));
    data_cnt += 1;
    return data[h].next();
}

void HashTable::__expand() {
    int new_size = __size * 2;
    HashTable temp_h(hash_func, new_size);
    for (int i = 0; i < __size; i++) {
        for (Node *p = data[i].next(); p; p = p->next()) {
            temp_h[p->key()] = p->value;
        }
    }
    swap(*this, temp_h);
    return ;
}

bool HashTable::erase(string s) {
    int h = hash_func(s) % __size;
    for (Node *p = &data[h]; p->next(); p = p->next()) {
        if (p->next()->key() != s) continue;
        p->erase_next();
        data_cnt -= 1;
        return true;
    }
    return false;
}

bool HashTable::find(string s) {
    return __find(s);
}
Node *HashTable::__find(string key) {
    int h = hash_func(key) % __size;
    for (Node *p = data[h].next(); p; p = p->next()) {
        if (p->key() == key) return p;
    }
    return nullptr;
}

//重载[]使我们的哈希表类表现的像一个数组
int &HashTable::operator[](string key) {
    Node *p;
    if (!(p = __find(key))) return (__insert(key)->value);     //如果找不到就插入一个新项
    return p->value;
}

//哈希函数1
int BKDRHash(string s) {
    int seed = 31;
    int h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

//哈希函数2
class APHash_Class {
public :
    int operator()(string s) {
        int h = 0;
        for (int i = 0; s[i]; i++) {
            if (i % 2) {
                h = (h << 3) ^ s[i] ^ (h >> 5);
            } else {
                h = ~((h << 7) ^ s[i] ^ (h >> 11));
            }
        }
        return h & 0x7fffffff;
    }
};

int main() {
    APHash_Class APHash;
    HashTable h1(BKDRHash);
    HashTable h2(APHash);
    int op;
    string s;
    cout << h1.capacity() << endl;
    cout << h2.capacity() << endl;
    h1["hello"] = 123;
    h1["world"] = 456;
    h1["haizei"] = 789;
    cout << h1.capacity() << endl;
    cout << h2.capacity() << endl;
    cout << h1["hello"] << " " << h1["world"] << " " << h1["hahaha"] << endl;
    while (cin >> op >> s) {
        switch (op) {
            case 0: {
                cout << "insert " << s << " to hash table 1 = ";
                cout << h1.insert(s) << endl;
                cout << "insert " << s << " to hash table 2 = ";
                cout << h2.insert(s) << endl;
            } break; // insert
            case 1: {
                cout << "erase " << s << " from hash table 1 = ";
                cout << h1.erase(s) << endl;
                cout << "erase " << s << " from hash table 2 = ";
                cout << h2.erase(s) << endl;
            } break; // erase
            case 2: {
                cout << "find " << s << " at hash table 1 = ";
                cout << h1.find(s) << endl;
                cout << "find " << s << " at hash table 2 = ";
                cout << h2.find(s) << endl;
            } break; // find
        }
    }
    return 0; 
}
