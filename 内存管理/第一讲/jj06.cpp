
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

namespace jj06 {
    class Foo {
    public:
        int _id;
        int _data;
        int _str;
        
    public:
        static void* operator new(size_t);
        static void  operator delete(void*, size_t);
        static void* operator new[](size_t);
        static void  operator delete [] (void*, size_t);
        
        Foo() : _id(0) { cout << "default ctor. this=" << this << " id=" << _id << endl; }
        Foo(int i) : _id(i) { cout << "ctor. this=" << this << " id=" << _id << endl; }
        ~Foo() { cout << "dtor. this=" << this << " id=" << _id << endl; }
        
        
    };
    
    void* Foo::operator new(size_t size) {
        Foo* p = (Foo*)malloc(size);
        cout << "Foo::operator new(), size=" << size << "\t  return: " << p << endl;
        return p;
    }
    
    void Foo::operator delete(void* pdead, size_t size)
    {
        cout << "Foo::operator delete(), pdead= " << pdead << "  size= " << size << endl;
        free(pdead);
    }
    
    void* Foo::operator new[](size_t size)
    {
        Foo* p = (Foo*)malloc(size);  //crash, 問題可能出在這兒
        cout << "Foo::operator new[](), size=" << size << "\t  return: " << p << endl;
        return p;
    }
    
    void Foo::operator delete[](void* pdead, size_t size)
    {
        cout << "Foo::operator delete[](), pdead= " << pdead << "  size= " << size << endl;
        free(pdead);
    }
    
    void test_overload_operator_new_and_array_new()
    {
        cout << sizeof(Foo) << endl;
        {
            Foo* p = new Foo(7);
            delete p;
            
            Foo* pArray = new Foo[5];   // 68 = 12*5 + 4*2
            delete [] pArray;
            
        }
        
        {
            cout << "testing global expression ::new and ::new[] \n";
            // 這會繞過 overloaded new(), delete(), new[](), delete[]()
            // 但當然 ctor, dtor 都會被正常呼叫.
            
            Foo* p = ::new Foo(7);
            ::delete p;
            
            Foo* pArray = ::new Foo[5];
            ::delete[] pArray;
        }
        
    }

    
}

int main()
{
    jj06::test_overload_operator_new_and_array_new();
    return 0;
}
