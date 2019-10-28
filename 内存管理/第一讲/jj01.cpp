
#include <iostream>
#include <complex>
#include <memory>

using namespace std;

namespace jj01 {
    void test_primitives() {
        void* p1 = malloc(512);     // 512字节
        free(p1);
        
        complex<int>* p2 = new complex<int>();
        delete p2;
        
        void* p3 = ::operator new(sizeof(complex<int>));  // 8个字节
        ::operator delete(p3);
        
        // C++ allocator
        int* p4 = allocator<int>().allocate(3);
        allocator<int>().construct(p4, 5);
        cout << *p4 << endl;
        allocator<int>().deallocate(p4, 3);
    }
}

int main()
{
    jj01::test_primitives();
    return 0;
}
