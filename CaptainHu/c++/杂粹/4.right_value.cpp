/*************************************************************************
	> File Name: 4.right_value.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 03:43:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define func(x) __func(x, "func(" #x ")")
#define func2(x) __func2(x, "func2(" #x ")")
void __func2(int &x, const char *str) {
    cout << str << " is left value" << endl;
    return ;
}

void __func2(int &&x, const char *str) {
    cout << str << " is right value " << endl;
    return ;

}
void __func(int &x, const char *str) {    //左值引用
    cout << str << " is left value" << endl;
    func2(x);
    return ;
}

void __func(int &&x, const char *str) {   //右值引用定义形式
    cout << str << " is right value " << endl;
    //func2(move(x));  //强制变右值特性
    func2(forward<int &&>(x));         //
    return ;
}

namespace haizei {
    
class vector {
public :
    vector(int n = 10) : __size(n), data(new int[n]) {}
    vector(const vector &v): __size(v.size()), data(new int[__size]) {
        cout << "deep copy" << endl;
        for (int i = 0; i < size(); i++) data[i] = v[i];
        return ;
    }
    vector(vector &&v) : __size(v.size()), data(v.data){
        cout << "move copy construcor" << endl;
        v.data = nullptr;
        v.__size = 0;
    }
    vector operator+(const vector &v) {
        vector ret(v.size() + this->size());
        vector &now = *this;
        for (int i = 0; i < size(); i++) {
            ret[i] = now[i];
        }
        for (int i = size(); i < ret.size(); i++) {
            ret[i] = v[i - size()];
        }
        return ret;
    } 
    int &operator[](int ind)  const {
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
    out << endl;
}

int main() {
    haizei::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    haizei::vector v3(v1 + v2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    haizei::vector v4(move(v1));
    cout << v1 << endl;
    cout << v4 << endl;
    //int x;
    //int &rx = x;   //左值引用
    int x = 1234, y = 456;
    func(1234);
    func(x);
    func(x + y);
    //到了下一行的时候，能通过单一变量访问到相关的值，能->左值  不能->右值
    func(x++);       
    func(++x);
    func(x + 123);
    cout << x << endl;
    func(x *= 2);
    cout << x << endl;
    func(y += 3);
    cout << y << endl;
    func(y * 3);
    cout << y << endl;
    return 0;
}
