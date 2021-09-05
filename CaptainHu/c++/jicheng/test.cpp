/*************************************************************************
	> File Name: test.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 09 Mar 2021 01:36:16 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public :
    Animal(string name) : name(name) {}
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
private :
    string name;
};

class Cat : public Animal {
public :
    Cat(string name) : Animal(name) {}
    void run() {
        cout << "I can run with four legs" << endl;
    }
};

int main() {
    Cat a("Tom");
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}
