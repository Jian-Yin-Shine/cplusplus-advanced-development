
#include <cstddef>
#include <memory>
#include <iostream>

using namespace std;

namespace jj05 {
    class Airplane {
        
    private:
        struct AirplaneRep {
            unsigned long miles;
            char type;
        };
        
    public:
        union {
            AirplaneRep rep;
            Airplane* next;
        };
        
    public:
        unsigned long getMiles() { return rep.miles; }
        char getType() { return rep.type; }
        void set(unsigned long m, char t) {
            rep.miles = m;
            rep.type = t;
        }
    
    public:
        static void* operator new(size_t);
        static void  operator delete(void*, size_t);
    
    private:
        static const int BLOCK_SIZE;
        static Airplane* headoffreelist;
    };
    
    Airplane* Airplane::headoffreelist;
    const int Airplane::BLOCK_SIZE = 512;
    
    void* Airplane::operator new(size_t size) {
        if (size != sizeof(Airplane))
            return ::operator new(size);
        
        Airplane* p = headoffreelist;
        if(p)
            headoffreelist = p->next;
        else {
            Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE*size));
            
            for(int i = 1; i < BLOCK_SIZE-1; ++i)
                newBlock[i].next = &newBlock[i+1];
            newBlock[BLOCK_SIZE-1].next = 0;
            
            p = newBlock;
            headoffreelist = &newBlock[1];
        }
        return p;
    }
    
    void Airplane::operator delete(void* deadObject, size_t size) {
        if (deadObject==0) return;
        if (size != sizeof(Airplane)) {
            ::operator delete(deadObject);
            return;
        }
        Airplane* carcass = static_cast<Airplane*>(deadObject);
        carcass->next = headoffreelist;
        headoffreelist = carcass;
    }
    
    void test_pre_class_allocator_2() {
        
        cout << sizeof(Airplane) << endl;
        size_t const N = 10;
        Airplane* p[N];
        
        for (int i = 0; i < N; ++i) {
            p[i] = new Airplane;
            cout << p[i] << endl;
        }
        
        p[0]->set(100, 'x');
        p[1]->set(1000, 'a');
        p[5]->set(2000, 'b');
        p[9]->set(50000, 'c');
        
        for(int i = 0; i < N; ++i)
            delete p[i];
        
    }
}

int main()
{
    jj05::test_pre_class_allocator_2();
    return 0;
}
