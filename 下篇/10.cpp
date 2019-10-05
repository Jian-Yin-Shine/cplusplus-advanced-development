
// 特化

#include <iostream>
#include <cstddef>

using namespace std;


template <typename Key>
struct hashs {};

template <>
struct hashs<char>{
    size_t operator()(char x) const { return x; }
};

template <>
struct hashs<int> {
    size_t operator()(int x) const { return x; }
};

template <>
struct hashs<long> {
    size_t operator()(long x) const {return x; }
};


int main()
{
    cout << hashs<long>()(1000) << endl;
    return 0;
}
