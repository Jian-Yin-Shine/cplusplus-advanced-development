
// 偏特化（个数上的，范围上的）

#include <iostream>
using namespace std;

template <class T1, class T2, int I>
class A {
public:
    void prints() {
        cout << "主模版" << endl;
    }
};

template <class T, int I>
class A<T, T*, I> {
public:
    void prints() {
        cout << "#1" << endl;
    }
};

template <class T, class T2, int I>
class A<T*, T2, I> {
public:
    void prints() {
        cout << "#2" << endl;
    }
};

template <class T>
class A<int, T*, 5> {
public:
    void prints() {
        cout << "#3" << endl;
    }
};

template <class X, class T, int I>
class A<X, T*, I> {
public:
    void prints() {
        cout << "#4" << endl;
    }
};

int main()
{
    A<int, int, 0> a1; a1.prints();
    A<int, int*, 1> a2; a2.prints();
    A<int*, int, 2> a3; a3.prints();
    A<int, char*, 3> a4; a4.prints();
    A<int, char*, 5> a5; a5.prints();
    return 0;
}
