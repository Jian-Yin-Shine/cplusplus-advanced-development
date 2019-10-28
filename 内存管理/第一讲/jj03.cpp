
#include <iostream>
#include <new>

using namespace std;

namespace jj03 {
    class A
    {
    public:
        int id;
        A() : id(0)      { cout << "default ctor. this=" << this << " id=" << id << endl; }
        A(int i) : id(i) { cout << "ctor. this=" << this << " id=" << id << endl; }
        ~A()             { cout << "dtor. this=" << this << " id=" << id << endl; }
    };
    
    
    void test_array_new_and_placement_new() {
    
        size_t size = 3;
        {
        
            // case 1
            A* buf = (A*) new char[sizeof(A)*size];
            A* tmp = buf;
            
            for (int i = 0; i < size; ++i) {
                new (tmp++) A(i);
            }
            
//            delete [] buf;
//            delete [] (char*)buf;
            
            delete buf;
            
            
            
        }
        
        {
            // case 2
            A* buf = new A[size];
            A* tmp = buf;
            
            for(int i = 0; i < size; ++i)
                new (tmp++)A(i);
            
            delete [] buf;
        }
    }
}

int main()
{
    jj03::test_array_new_and_placement_new();
    return 0;
}
