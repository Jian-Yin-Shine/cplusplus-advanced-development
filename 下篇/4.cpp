
// pointer-like classes, 智能指针(处理* ->)
template<class T>
class shared_ptrs{
public:
    shared_ptrs(T* p):px(p) { }
    
    T& operator*() const {
        return *px;
    }
    
    T* operator->() const {
        return px;
    }
    
private:
    T* px;
    long* pn;
};

#include <iostream>
using namespace std;

struct Foo {
    
    void method() { cout << "Foo's method" << endl; }
};

int main() {
    shared_ptrs<Foo> sp(new Foo);
    Foo f(*sp);
    sp->method();
    
    return 0;
}


// 智能指针，关于迭代器；迭代器支持的操作更多++,--等
