
// 继承，组合下的构造与析构

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base init" << endl;
    }
    
    virtual ~Base() {
        cout << "Base del" << endl;
    }
};

class Compontent {
public:
    Compontent() {
        cout << "Compotent init" << endl;
    }
    ~Compontent() {
        cout << "Compotent del" << endl;
    }
};

class Child : public Base {
public:
    Child() {
        cout << "Child init" << endl;
    }
    
    virtual ~Child() {
        cout << "Child del" << endl;
    }
private:
    Compontent ts;
};

int main()
{
    Child a;
    
    return 0;
}
