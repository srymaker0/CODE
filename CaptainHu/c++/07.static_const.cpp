/*************************************************************************
	> File Name: 07.static_const.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 07 Mar 2021 01:30:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People {
public :
    People() {
        People::total_num += 1;                //加People作用域是为了防止和其他变量重名产生冲突
    }
    static void say_count() {
        cout << People::total_num << endl;
    }
    void say() const {
        cout << "hahaha, funny!" << endl;
        output();     //const
        say_cnt += 1;
    }
    void output() {
        cout << "non-const output function" << endl;
    }
    void output() const {
        cout << "const output function" << endl;
    }
    ~People() {
        People::total_num -= 1;
    }
private : 
    mutable int say_cnt;
    static int total_num;                    //不是类属性的定义，是类属性的声明
                                            //在类内声明加上static为了和成员属性作区分  
};

int People::total_num = 0;                  //类属性的定义  在定义时static关键字可以不需要

int main() {
    People hug, xiao_hug;
    hug.say_count();                        //调用类方法1
    People::say_count();                    //调用类方法2  
    {
        People hug, xiao_hug;
        People::say_count();
    }
    People::say_count();
    const People xiaobo;
    xiaobo.say();
    return 0;
}
