/*************************************************************************
	> File Name: 6.is_prime.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

// 模板可以传整形
template<int n>
struct sum {
    static constexpr int r = n + sum<n - 1>::r;
};

// 模板特化，当n=1时，返回r=1
template<>
struct sum<1> {
    static constexpr int r = 1;
};


//========================================================
template<int n>
struct getBad {
    static constexpr int r = (n <= 5);
};

template<int n>
struct getGood {
    static constexpr int r = (n > 5);
};

// 声明，只需判断即可，没必要实现普通的模版类
template<int n, int m> struct judge;

// 特化版，<1, 0>表示bad
template<>
struct judge<1, 0> {
    static constexpr char *r = (char *)"bad";       //编译期常量指针，constexpr在编译期就要确定变量
};

// <0, 1>表示good
template<>
struct judge<0, 1> {
    static constexpr char *r = (char *)"good";
};

template<int n>
struct score {
    static constexpr char *r = judge<getBad<n>::r, getGood<n>::r>::r;       //先调用get***判断n，然后再调用judge判断参数符合哪种情况
};
//========================================================

template<int n>
struct isEven {
    static constexpr int r = !(n % 2);
};

template<int n> struct judge1;
template<>
struct judge1<0> {
    static constexpr char *r = (char *)"no";
};

template<>
struct judge1<1> {
    static constexpr char * r = (char *)"yes";
};

template<int n>
struct is_even {
    static constexpr char *r = judge1<isEven<n>::r>::r;
};
//========================================================

template<int n, int m>
struct isPrime { 
    static constexpr int r = (n % m == 0 ? 0 : isPrime<n, m - 1>::r);     //若被整除，则不是素数并且递归调用isPrime 
};

// 偏特化
template<int n>
struct isPrime<n, 1> {                                   //若在m = 1之前都没有整除，那就是素数了
    static constexpr int r = 1;           
};


template<int n>
struct is_prime {
    static constexpr int r = isPrime<n, (int)sqrt(n)>::r;      //把r定义成编译器常量，就不用在类外初始化了
};

// 特化
template<>
struct is_prime<1> {
    static constexpr int r = 0;       
};

int main() {
    cout << sum<5>::r << endl;          // for
    cout << score<10>::r << endl;       // good, if
    cout << score<4>::r << endl;        // bad, if
    cout << is_even<3>::r << endl;      // no
    cout << is_even<4>::r << endl;      // yes
    cout << is_prime<2>::r << endl;     // 1
    cout << is_prime<13>::r << endl;    // 1
    cout << is_prime<25>::r << endl;    // 0
    cout << is_prime<27>::r << endl;    // 0
    cout << is_prime<9973>::r << endl;  // 1
    cout << is_prime<1>::r << endl;  // 0
    return 0;
}
