
#include <iostream>
#include <cstddef>
#include <string>
#include <memory>

using namespace std;

namespace jj09 {
    class allocator {
    private:
        struct obj {
            struct obj* next;
        };
    public:
        void* allocate(size_t);
        void  deallocate(void*);
        void check();
    private:
        obj* freeStore = nullptr;
        const int CHUNK = 5;
    
    };
    
    void* allocator::allocate(size_t size) {
        obj* p;
        if (!freeStore) {
            size_t chunk = CHUNK * size;
            freeStore = p = (obj*)malloc(chunk);
            for (int i = 0; i < CHUNK-1; ++i) {
                p->next = (obj*)((char*)p + size);
                p = p->next;
            }
            p->next = nullptr;
        }
        p = freeStore;
        freeStore = freeStore->next;
        
        return p;
    }
    
    void allocator::deallocate(void* p) {
        ((obj*)p)->next = freeStore;
        freeStore = (obj*)p;
    }
    
    void allocator::check()
    {
        obj* p = freeStore;
        int count = 0;
        while(p) {
            cout << p << endl;
            p = p->next;
            count ++;
        }
        cout << count << endl;
    }
    
    class Foo {
    public:
        long L;
        string str;
        static allocator myalloc;
    public:
        Foo(long l) : L(l) { }
        static void* operator new(size_t size) {
            return myalloc.allocate(size);
        }
        static void  operator delete(void* pdead) {
            myalloc.deallocate(pdead);
        }
    };
    allocator Foo::myalloc;
    
    
    void test_static_allocator_3()
    {
        Foo* p[10];
        for (int i = 0; i < 10; ++i) {
            p[i] = new Foo(i);
            cout << p[i] << ' ' << p[i]->L << endl;
        }
        
        for (int i = 0; i < 10; ++i) {
            delete p[i];
        }
        
    }
}

int main()
{
    jj09::test_static_allocator_3();
    return 0;
}
