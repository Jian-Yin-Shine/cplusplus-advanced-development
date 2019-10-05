
// 成员模版
// 一般是构造函数

/*
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class pairs {
    typedef T1 first_type;
    typedef T2 second_type;
    
    pairs() : first(T1()), second(T2()) {}
    pairs(const T1& a, const T2& b) : first(a), second(b) {}
    
    template <typename U1, typename U2>
    pairs(const pairs<U1, U2>& p) : first(p.first), second(p.second) {}
    
    T1 first;
    T2 second;
};

class Base1{};
class Derived1: public Base1 {};

class Base2{};
class Derived2: public Base2 {};

int main() {
    pairs<Derived1, Derived2> p;
    pairs<Base1, Base2> p2(p);
    
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct  Printer {
    ostream& os;
    Printer(ostream& os) : os(os) {}
    
    template<typename T>
    void operator()(const T& obj) { os << obj << ' '; }
};

int main()
{
    vector<int> v = {1, 2, 3};
    for_each(v.begin(), v.end(), Printer(cout));
    string s = "abc";
    for_each(s.begin(), s.end(), Printer(cout));
    
    return 0;
}
