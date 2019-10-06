
// reference

#include <iostream>

using namespace std;

typedef struct Stag{
    int a, b, c, d;
} S;

int main()
{
    double x = 0;
    double* p = &x;
    double& r = x;
    
    cout << sizeof(x) << endl; // 8
    cout << sizeof(p) << endl; // 8
    cout << sizeof(r) << endl; // 8
    
    cout << p << endl;
    cout << *p << endl;
    cout << x << endl;
    cout << r << endl;
    cout << &x << endl;
    cout << &r << endl;
    
    S s;
    S& rs = s;
    cout << sizeof(s) << endl;
    cout << sizeof(rs) << endl;
    
    cout << &s << endl;
    cout << &rs << endl;
    
    
    return 0;
}
