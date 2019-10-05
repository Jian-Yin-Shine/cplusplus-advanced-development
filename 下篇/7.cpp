
// 类模版
#include <iostream>
using namespace std;

template<typename T>
class complex{
    
    friend ostream& operator<< (ostream& os, const complex<double>);
    friend ostream& operator<< (ostream& os, const complex<int>);
public:
    complex(T r = 0, T i = 0) : re(r), im(i) {}
    complex& operator+= (const complex&);
    
    T real() const { return re; }
    T imag() const { return im; }
private:
    T re, im;
};

ostream& operator << (ostream& os, const complex<double> a) {
    os << a.re << "+" << a.im << "i";
    return os;
}

ostream& operator << (ostream& os, const complex<int> a) {
    os << a.re << "+" << a.im << "i";
    return os;
}

int main() {
    complex<double> c1(1.0, 2.0);
    complex<double> c2(2.0, -2.0);
    
    cout << c1 << endl;
    
    complex<int> c3(1,2);
    cout << c3 << endl;
    
    return 0;
}
