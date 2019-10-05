
// 函数模板
#include <iostream>

using namespace std;

template <typename T>
const T& mins(const T& a, const T& b) {
    return a < b ? a : b;
}

class stone {
    friend ostream& operator << (ostream& os, const stone& );
public:
    stone(int w, int h, int we) : _w(w), _h(h), _we(we) {}
    bool operator < (const stone& rhs) const {
        return _we < rhs._we;
    }
private:
    int _w, _h, _we;
};

ostream& operator << (ostream& os, const stone& a) {
    os << a._we;
    return os;
}

int main() {
    int a1 = 3, a2 = 4;
    cout << mins(a1, a2) << endl;
    
    stone r1(1,2,3), r2(3,1,1);
    cout << mins(r1, r2) << endl;
    
    return 0;
}
