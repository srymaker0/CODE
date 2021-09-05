/*************************************************************************
	> File Name: 1.hash_table.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 10 Jul 2021 04:13:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
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
        }
        return ;
    }
    // 查找元素
    bool find(string s) {
        int ind = hash_func(s) % data.size();       // 获取这个字符串的哈希值
        recalc_ind(ind, s);                         // 冲突处理 重获下标
        return flag[ind]; 
    }
private:
    int cnt;
    vector<string> data;    
    vector<bool> flag;                              // 标记数组，判断data数组中是否有值
    // 扩容
    void expand() {
        int n = data.size() * 2;                    // 原来的两倍容量 
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            if (flag[i] == false) continue;
            h.insert(data[i]);
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
        int t = 1;                                  // 开方定址
        // 若此下标有值，并且data中存储的值不是s  找下一个可以存放的地址
        while (flag[ind] && data[ind] != s) {
            ind += t * t;
            t += 1;                                 // 平方法 每次+1
            ind %= data.size();                     // 哈希映射
        }
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
