
// namespace

#include "6.1.cpp"
#include "6.2.cpp"
#include <iostream>

using namespace std;

int main() {
    using namespace First;  // 使用整个命名空间
    using namespace Second::Internal; // 使用嵌套在里面的整个命名空间
    
    cout << i << endl;
    cout << Second::i << endl;
    P p(1,1);
    
    
    return 0;
}

