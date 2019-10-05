
// function-like classes, 仿函数(函数对象)
// 操作符重载()
struct absInt {
    int operator() (int val) const {
        return val < 0 ? -val : val;
    }
};

#include <iostream>
using namespace std;

int main() {
    int i = -42;
    absInt abs;
    cout << abs(i) << endl;
    return 0;
}
