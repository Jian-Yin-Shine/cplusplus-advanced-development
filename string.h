#ifndef __MYSTRING__
#define __MYSTRING__

class String 
{
public:
    String(const char* cstr=0);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const { return m_data; }
private:
    // 指向数组元素的指针，可以做迭代器运算
    // int *p = nums; // 指向数组第一个元素的地址 = int *p = &nums[0]
    // 做迭代器运算 p++
    // 第二种理解： int *p = &obj; 指向一个int对象的指针，但是不是数组，不能做迭代器运算
    // 例如：
    /*
    char strs[] ={'a', 'b', 'c'};
    char *str = strs;
    while(*str) {
        cout << *(str++) ;
    }
    cout << endl;
    char c = 'b';
    str = &c;*/
    char* m_data;
};

#include <cstring>

inline
String::String(const char* cstr) {
    if(cstr) {
        m_data = new char[strlen(cstr) + 1];    
        strcpy(m_data, cstr);
    }    
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::String(const String& str) {
    m_data = new char[ strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline
String& String::operator=(const String& str) {
    if (this==&str) 
        return *this;
    delete[] m_data;
    m_data = new char[ strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline
String::~String() {
    delete[] m_data;    
}

#include <iostream>
using namespace std;
ostream& operator<< (ostream& os, const String str) {
    os << str.get_c_str();    
    return os;
}
#endif
