/*************************************************************************
	> File Name: 3.Animal.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 07 Mar 2021 02:32:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public :
    Animal(string name) : name(name) {}
    virtual void run()  {                       //virtual 虚函数
        cout << "I don't know how to run" << endl;
    }
    virtual void getName() final {}             //final->子类中不允许重载这个方法
    virtual void fl1() {}
private :
    string name;
};

class Cat : public Animal {
public :
    Cat(string name) : Animal(name) {}
    void run() override final {                 //override起到说明作用
        cout << "I can run with four legs" << endl;
    }
    void fl1() override {}
};

/*
class Tigger : public Cat {
public :
    void run() {}        //编译器会报错， final关键字->禁止重载
};
*/

class People : public Animal{
public :
    People(string name) : Animal(name) {}
    void run() {
        cout << "I can run with two legs" << endl;
    }
};

class Bat : public Animal {
public :
    Bat(string name) : Animal(name) {}
    void run() {
        cout << "I can fly" << endl;
    } 
};

int main() {
    #define MAX_N 10
    srand(time(0));
    Animal **zoo = new Animal*[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        switch (rand() % 3) {
            case 0: zoo[i] = new Cat("cat"); break;
            case 1: zoo[i] = new People("people"); break;
            case 2: zoo[i] = new Bat("bat"); break;
        }
    }
    for (int i = 0; i < MAX_N; i++) zoo[i]->run();  //随机调用，足以看出虚函数在运行期才确定
    return 0; 
}
