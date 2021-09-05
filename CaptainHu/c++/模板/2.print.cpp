/*************************************************************************
	> File Name: 2.print.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 13 Mar 2021 09:03:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class PRINT {
public :
    template<typename T>        //模板成员方法
    PRINT &operator()(T a) {    //重载()运算符
        cout << a << endl;
        return *this;
    }
};

int main() {
    PRINT print;         //不需要加<>
    print(123)("hello world")("hello haizei")(456)(789);
    return 0;
}
