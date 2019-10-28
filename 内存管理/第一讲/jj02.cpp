
#include <iostream>
#include <string>
#include <memory>

using namespace std;

namespace jj02 {
    class A
    {
    public:
        int id;
        A() : id(0) { cout << "default ctor. this=" << this << " id=" << id << endl;}
        A(int i) : id(i) { cout << "ctor. this=" << this << " id=" << id << endl; }
        ~A() { cout << "dtor. this=" << this << " id=" << id << endl; }
    };
    
    void test_call_ctor_directly()
    {
        string* pstr = new string("abc");
        cout << "str= " << *pstr << endl;
//        pstr->string::basic_string("jjhou");
        
        // 指针不能调用构造函数，能调用析构函数
        pstr->~string();
        cout << "str= " << *pstr << endl;
        
        
        A* pa = new A(1);
        cout << pa->id << endl;
        delete pa;
//        pa->A::A(3);
        
//        A::A(5); VC ok , gcc no
        
        
        // 模仿new
        void* p = ::operator new(sizeof(A));
        cout << "p=" << p << endl;
        pa = static_cast<A*>(p);
//        pa->A::A(2);   用指针掉构造函数，只能是编译器
        cout << pa->id << endl;
        
        // 模仿delete
        pa->~A();
        ::operator delete(pa);
        
    }
}


int main()
{
    jj02::test_call_ctor_directly();
    
    return 0;
}
