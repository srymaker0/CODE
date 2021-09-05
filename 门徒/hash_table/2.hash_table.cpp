/*************************************************************************
	> File Name: 1.hash_table.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 10 Jul 2021 04:13:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class HashTable {
public:
    HashTable(int n = 100) : data(n), flag(n), cnt(0) {}
    // 插入元素
    void insert(string s) {
        int ind = hash_func(s) % data.size();       // 1、计算哈希值 
        recalc_ind(ind, s);                         // 2、冲突处理
        // 3、插入元素
        if (flag[ind] == false) {
            data[ind] = s;
            flag[ind] = true;
            cnt += 1;                               // 元素个数+1
            // 扩容 根据装填因子 0.75 
            if (cnt * 100 > data.size() * 75) {
                expand();
            }
        } else if (data[ind] != s) {
            buff.insert(s);                         // 发生冲突，放入缓冲区[+]
        }
        return ;
    }
    // 查找元素
    bool find(string s) {
        int ind = hash_func(s) % data.size();       // 获取这个字符串的哈希值
        recalc_ind(ind, s);                         // 冲突处理 重获下标
        if (flag[ind] == false) return false;       // [+]
        if (data[ind] == s) return true;            // 查看data数组中有没有s元素，没有则可能在缓冲区中[+] 
        return buff.find(s) != buff.end();          // 去set容器的公共溢出缓冲区中找[+]
    }
private:
    int cnt;
    vector<string> data;    
    vector<bool> flag;                              // 标记数组，判断data数组中是否有值
    set<string> buff;                               // set容器作为公共溢出缓冲区[+]
    // 扩容
    void expand() {
        int n = data.size() * 2;                    // 原来的两倍容量 
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            if (flag[i] == false) continue;
            h.insert(data[i]);
        }
        // 拷贝缓冲区的元素
        for (auto x : buff) {
            h.insert(x);
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
