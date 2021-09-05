/*************************************************************************
	> File Name: 8.my_hash.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 07 Mar 2021 07:13:24 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Node {
public :
    Node() = default;
    Node(string, Node *);
    string data();
    Node *next();
    void insert(Node *);
    void erase_next();
private :
    string __data;
    Node *__next;
};

class HashTable {
public :
    typedef function<int(string)> HASH_FUNC_T;
    HashTable(HASH_FUNC_T hash_func, int size);
    void insert(string);
    void erase(string);
    bool find(string);
private :
    int size;
    HASH_FUNC_T hash_func;
    vector<Node *> data;
};

Node::Node(string data, Node *next) : __data(data), __next(next) {}
string Node::data() { return this->__data; }
Node *Node::next() { return this->__next; }
void Node::insert(Node *p) { p->__next = this->__next; this->__next = p; }
void Node::erase_next() {
    if (this->__next == nullptr) return ;
    Node *p = this->__next;
    this->__next = this->__next->__next;
    delete q;
    return ;
}

HashTable::HashTable(HASH_FUNC_T hash_func, int size = 10000) 
: size(size), data(size), hash_func(hash_func) {}
void HashTable::insert(string s) {
    int h = hash_func(s) % size;
    data[h].insert(new Node(s));
    return ;
}

void HashTable::erase(string s) {
    int h = hash_func(s) % size;
    for (Node *p = data[h].next(); p; p = p->next()) {
        if (p->next()->data() != s) continue;
        p->erase_next();
    } 
    return ;
}

bool HashTable::find(string s) {
    int h = hash_func(s) % size;
    for (Node *p = data[h].next(); p; p = p->next()) {
        if (p->data() == s) return true;
    }
    return false;
}

int BKDRHash(string s) {
    int seed = 31;
    int h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

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
    while (cin >> op >> s) {
        switch (op) {
            case 0: {
                cout << "insert " << s << " to hash table 1 = ";
                cout << h1.insert(s) << endl;
                cout << "insert " << s << "to hash table 2 = ";
                cout << h2.insert(s) << endl;
            } break;
            case 1: {
                cout << "erase " << s << " to hash table 1 = ";
                cout << h1.erase(s) << endl;
                cout << "erase " << s << "to hash table 2 = ";
                cout << h2.erase(s) << endl;
            } break;
            case 2: {
                cout << "search " << s << " to hash table 1 = ";
                cout << h1.search(s) << endl;
                cout << "search " << s << "to hash table 2 = ";
                cout << h2.search(s) << endl;
            } break;
        }
    }
    return 0;
}
