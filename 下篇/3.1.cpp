#include <iostream>

using namespace std;

// 一步转换抑制 explicit

class Fraction{
    friend ostream& operator << (ostream& os, const Fraction& f);
public:
    Fraction(int num, int den=1) : m_numerator(num), m_denominator(den) {}
    
    Fraction operator + (const Fraction& f) {
        Fraction ans(this->m_numerator*f.m_denominator + this->m_denominator*f.m_numerator,
                     this->m_denominator*f.m_denominator);
        return ans;
    }
    
    
private:
    int m_numerator;    // 分子
    int m_denominator;  // 分母
};

ostream& operator << (ostream& os, const Fraction& f) {
    return os << f.m_numerator << "/" << f.m_denominator;
}



int main() {
    Fraction f(3,5);
    Fraction d2 = f + 4;
    cout << d2 << endl;
    return 0;
}
