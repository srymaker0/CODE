/*************************************************************************
	> File Name: 4.right_value.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 03:43:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
namespace haizei {
    
class vector {
public :
    vector(int n = 10) : __size(n), data(new int[n]) {
        cout << "default constructor" << endl;
    }
    vector(const vector &v): __size(v.size()), data(new int[__size]) {
        cout << "deep copy constructor" << endl;
        for (int i = 0; i < size(); i++) data[i] = v[i];
        return ;
    }
    vector(vector &&v) : __size(v.size()), data(v.data){             //移动构造，提高拷贝效率
        cout << "move copy construcor" << endl;
        v.data = nullptr;                             //避免把刚拿过来的data被析构掉 
        v.__size = 0;
    }
    vector operator+(const vector &v) {               //重载+运算符  让vector支持+
        vector ret(v.size() + this->size());
        vector &now = *this;                          //第一个数组
        for (int i = 0; i < size(); i++) {            //拷贝第一个数组的数据
            ret[i] = now[i];
        }
        for (int i = size(); i < ret.size(); i++) {   //拷贝第二个数组的数据
            ret[i] = v[i - size()];
        }
        return ret;            
    } 
    int &operator[](int ind)  const {           //返回引用，是一个左值 让vector支持[] 
        return this->data[ind];
    }
    int size() const { return __size; }         
    ~vector() {
        if (data) delete[] data;
        data = nullptr;
        __size = 0;
    }
private : 
    int __size;
    int *data;
};

} // end of haizei
    
ostream &operator<<(ostream &out, const haizei::vector &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

int main() {
    haizei::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    //v1 + v2会产生一个临时变量 迟早会被回收，那为什么不直接把临时变量的值直接给v3呢
    haizei::vector v3(v1 + v2);           
    cout << v1 << endl;                   
    cout << v2 << endl;
    cout << v3 << endl;
    haizei::vector v4(move(v1));          // 显示的调用移动构造  把v1的数据直接给v4 然后v1直接没了
    cout << v1 << endl;                   // 输出空
    cout << v4 << endl;                   
    return 0;
}
