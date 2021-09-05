/*************************************************************************
	> File Name: 4.rand.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 04 Apr 2021 05:34:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace haizei {
    static int __seed = 3;
    void srand(int seed) {
        __seed = seed;
        return ;
    }
    int rand() {
        return __seed = __seed * 3 % 101;
    }
}

int main() {
    //计算机中的随机函数是伪随机 只要起始点一样随机出来的数就一样
    haizei::srand(time(0));     
    for (int i = 0; i < 10; i++) {
        cout << haizei::rand() << endl;
    }
    return 0;
}
