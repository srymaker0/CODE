/*************************************************************************
	> File Name: 1.cat.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 06 Mar 2021 07:04:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public :
    Animal(string name = "mimi") : name(name) {
        cout << "animal default constructor" << endl;
    }
    Animal(const Animal &a) : name(a.name) {
        cout << "animal copy constructor" << endl;
    }
    ~Animal() {
        cout << "animal default destructor" << endl;
    }
    Animal &operator=(const Animal &a) {
        this->name = a.name;
        return *this;
    }
    void say() {
        cout << "my name is " << name << endl;
    }
    void rename(string name) {
        this->name = name;
    }
protected :                        // 只有子类能访问
    string name;
};

//继承权限public
class Cat : public Animal {
public :
    Cat() : Animal("Cat MIMI") {       //显示的调用父类的构造函数， 不写则是隐式的
        cout << "Cat default constructor" << endl;
    }
    Cat(const Cat &c) : Animal(c) {       //必须显示的调用父类的拷贝构造函数 不然将发生不正确的拷贝
        cout << "Cat copy constructor" << endl;
    }
    Cat &operator=(const Cat &c) {
        this->Animal::operator=(c);         //显示的调用父类的赋值拷贝构造函数
        return *this;
    }
    void say1() {
        cout << "miaomiaomiao, my name is " << name << endl;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

//class Tigger :

class A {
public:
    A() : x(123) {}
    int x;
};
//virtual 必须继承自A 虚继承
class B : virtual public A {
public :
    void setX(int x) { this->x = x; return ;}
};

class C : virtual public A {
public :
    int getX() { return x; }
};

class D : public B, public C {};


int main() {
    D d;
    cout << "get X : " << d.getX() << endl;
    d.setX(12345);
    cout << "get X : " << d.getX() << endl;
   
    cout << sizeof(Animal) << " " << sizeof(Cat) << endl;
    Cat c;
    Cat a = c;
    a.say1();
    c.say1();
    
    Animal *p = &c;  //将子类转换为父类
    p->say();
    return 0;
}
