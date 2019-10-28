
#include <iostream>
#include <cstddef>

using namespace std;

namespace jj04 {
    class Screen {
    public:
        Screen(int x) : i(x) { cout << "ctor " << this << " id=" << i << endl; }
        ~Screen() { cout << "dtor" << this << " id=" << i << endl; }
        int get() { return i; }
        
        void* operator new(size_t);
        void  operator delete(void*);
        
    private:
        Screen* next;
        static Screen* freeStore;
        static const int screenChunk;
        
    private:
        int i;
    };
    
    Screen* Screen::freeStore = 0;
    const int Screen::screenChunk = 5;
    
    void* Screen::operator new(size_t size) {
        Screen *p;
        if (!freeStore) {
            size_t chunk = screenChunk * size;
            freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
            
            for (; p!= &freeStore[screenChunk-1]; ++p)
                p->next = p + 1;
            p->next = 0;
        }
        p = freeStore;
        freeStore = freeStore->next;
        
        return p;
    }
    
    void Screen::operator delete(void* p) {
        static_cast<Screen*>(p)->next = freeStore;
        freeStore = static_cast<Screen*>(p);
    }
    
    
    void test_per_class_alloctor_1() {
        size_t const N = 15;
        Screen* p[N];
        
        cout << sizeof(Screen) << endl;
        
        for (int i = 0; i < N; ++i)
            p[i] = new Screen(i);
        
        for (int i = 0; i < N; ++i)
            delete p[i];
        
    }
    
}

int main()
{
    jj04::test_per_class_alloctor_1();
    
    return 0;
}
