
#include <vector>
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

namespace jj07 {
    class Bad { };
    class Foo {
    public:
        Foo() { cout << "Foo::Foo()" << endl; }
        Foo(int) {
            cout << "Foo::Foo(int)" << endl;
//            throw Bad();
        }
        
        
        void* operator new(size_t size){
            cout << "operator new(size_t size), size= " << size << endl;
            return malloc(size);
        }
        void operator delete(void*, size_t) // or (void*)
        {
            cout << "operator delete(void*,size_t)  " << endl;
        }
        
        void* operator new(size_t size, void* start){
            cout << "operator new(size_t size, void* start), size= " << size << "  start= " << start << endl;
            return start;
        }
        void operator delete(void*, void*)
        {
            cout << "operator delete(void*,void*)  " << endl;
        }
        
        void* operator new(size_t size, long extra){
            cout << "operator new(size_t size, long extra)  " << size << ' ' << extra << endl;
            return malloc(size + extra);
        }
        void operator delete(void*, long)
        {
            cout << "operator delete(void*,long)  " << endl;
        }
        
        void* operator new(size_t size, long extra, char init){
            cout << "operator new(size_t size, long extra, char init)  " << size << ' ' << extra << ' ' << init << endl;
            return malloc(size + extra);
        }
        void operator delete(void*, long, char)
        {
            cout << "operator delete(void*,long,char)  " << endl;
        }
    private:
        int m_i;

    };
    
    void test_overload_placement_new()
    {
        Foo* p1 = new Foo;
        delete p1;
        
        Foo start;
        Foo* p2 = new(&start)Foo;
        
        Foo* p3 = new(100)Foo;
        Foo* p4 = new(100, 'a')Foo;
        
        Foo* p5 = new(100)Foo(1);
        Foo* p6 = new(100, 'a')Foo(1);
        
        Foo* p7 = new(&start)Foo(1);
//        Foo* p8 = new Foo(1);
        
        delete p2;
        delete p3;
        delete p4;
        delete p5;
        delete p6;
        delete p7;
    }
}

int main()
{
    jj07::test_overload_placement_new();
    return 0;
}
