/*************************************************************************
	> File Name: 05.malloc_new.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 03 Mar 2021 10:15:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

class B {
public :
    B() {
        cout << " B default constructor" << endl;
    }
    ~B() {
        cout << " B destructor" << endl;
    }
};

int main() {
    int n = 10;
    cout << "malloc int" << endl;
    int *data1 = (int *)malloc(sizeof(int) * n);
    free(data1);
    cout << "new int" << endl;
    int *data2 = new int[n];
    delete[] data2;
    cout << "malloc A" << endl;
    A *Adata1 = (A *)malloc(sizeof(A) * n);
    for (int i = 0; i < n; i++) {
        new(Adata1 + i) A();                 //原地构造
        //new(Adata1 + i) B();               //是可以的
    }
    free(Adata1);
    cout << "new A" << endl;
    A *Adata2 = new A[n];
    A *Adata3 = new A;
    delete[] Adata2;
    delete Adata3;
    return 0;
}
