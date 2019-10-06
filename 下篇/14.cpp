// C++ 11的三个主题
// 1. 数量不定的模板参数
// 2. auto
// 3. for

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print()
{
    
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    cout << firstArg << endl;
    print(args...);
}

int main()
{
    print(7.5, "hello", 42);
    
    vector<int> vec = {0,1,2,3,4};
    auto iter = find(vec.begin(), vec.end(), 3);
    cout << *iter << endl;
    
    for(auto& elem : vec) {
        elem*= 3;
    }
    
    for (auto elem : vec) {
        cout << elem;
    }
    cout << endl;
    
    return 0;
}
