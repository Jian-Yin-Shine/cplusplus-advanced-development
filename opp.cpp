// 参考：https://www.runoob.com/cplusplus/cpp-polymorphism.html

#include <iostream>

using namespace std;

class Shape {
public:
    Shape(int a =0, int b = 0) {
        width = a;
        height = b;
    }
    virtual void paint() = 0;
protected:
    int width, height;
};

class Rect : public Shape {
public:
    Rect(int a, int b) : Shape(a, b) { }
    void paint() {
        cout << "This is Rect, and the area is "<< width * height << endl;    
    }
};

class Circle : public Shape{
public:
    Circle(int r = 0) : Shape(r, r) { }
    void paint() {
        cout << "This is Circle, and the area is " << width*height*3.14 << endl;    
    }
};

int main() 
{
    /*
    Rect a(3,4);
    a.paint();
    Circle b(3);
    b.paint();*/
    
    Shape * paint;
    Rect a(3,4);
    Circle b(3);

    paint = &a;
    paint->paint();
    
    paint = &b;
    paint->paint();

    return 0;    
}
