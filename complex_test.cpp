#include <iostream>
#include "complex.h"

using namespace std;

int main() {
    complex a(1,4), b(2, 3);
    cout << a << a+b;
    cout << a + 3;
    a += b;
    cout << a;
    return 0;    
}
