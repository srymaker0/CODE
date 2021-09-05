/*************************************************************************
	> File Name: templete_reference.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 14 Mar 2021 02:40:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace haizei {
template<typename T>
void swap(T &&a, T &&b) {    
    typename remove_reference<T>::type c;
    c = a; a = b ; b = c;
    return ;
}

} // end of haizei
int main() {
    int n = 123, m = 456;
    haizei::swap(n, m);
    cout << n << " " << m << endl;
    //haizei::swap(789, n);   // 报错
    return 0;
}
