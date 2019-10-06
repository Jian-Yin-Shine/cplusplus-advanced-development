
// 虚函数and 虚表

#include <iostream>
using namespace std;

class Shape {
public:
    Shape(int a = 0, int b = 0) : width(a), height(b) { }
    virtual int area() {
        cout << "Parent class area :" ;
        return 0;
    }
protected:
    int width, height;
};


class Rectangle: public Shape{
public:
    Rectangle(int a=0, int b=0): Shape(a, b) { }
    virtual int area()
    {
        cout << "Rectangle class area :" ;
        return (width * height);
    }
};

class Squre: public Rectangle{
public:
    Squre(int a=0): Rectangle(a, a) { }
    int area()
    {
        cout << "Squre class area :" ;
        return (width * height);
    }
};

class Triangle: public Shape{
public:
    Triangle( int a=0, int b=0): Shape(a, b) { }
    virtual int area()
    {
        cout << "Triangle class area :" ;
        return (width * height / 2);
    }
};


int main()
{
    Shape* sp;
    Rectangle rec(3,4);
    sp = &rec;
    int area = sp->area();
    cout << area << endl;
    
    sp = new Triangle(3,4);
    area = sp->area();
    cout << area << endl;
    
    sp = new Squre(3);
    area = sp->area();
    cout << area << endl;
    
    return 0;
}
