
// 模版模版参数
#include <iostream>
#include <string>
#include <list>

using namespace std;


template <typename T, template <typename U> class Container >
class XCLs
{
private:
    Container<T> c;
};


template <typename T>
class test {
private:
    T t;
};

template<typename T>
using Lst = list<T, allocator<T> >;

int main()
{
    XCLs<string, test> mylst1;
    
    
    XCLs<string, Lst> mylist2;
    return 0;
}
