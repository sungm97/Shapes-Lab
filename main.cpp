#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class Shape
{
    public:
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;

};
class Rectangle : public Shape
{
    public:
        double width;
        double length;
        Rectangle(){}
        Rectangle(double w, double l)
        {
            width = w;
            length = l;
        }
        double getArea() override
        {
            return width * length;
        }
        double getPerimeter() override
        {
            return (2 * width) + (2 * length);
        }
};
class RightTriangle : public Shape
{
    public:
        double height;
        double base;
        RightTriangle(){}
        RightTriangle(double h, double b)
        {
            height = h;
            base = b;
        }
        double getArea() override
        {
            return (base * height)/2;
        }
        double getPerimeter() override
        {
            double hypotenuse = sqrt(base * base + height * height);
            return (base + height + hypotenuse);
        }
};
class Square : public Rectangle
{
    public:
        Square(double s)
        {
            width = s;
            length = s;
        }
};
class IsocelesRightTriangle : public RightTriangle
{
    public:
        IsocelesRightTriangle(double s)
        {
            height = s;
            base = s;
        }
};

int main()
{
    Rectangle rect(5.0, 6.0);
    RightTriangle tri(8.0, 15.0);
    Square square(5.0);
    IsocelesRightTriangle iso(10);
    cout << rect.getArea() << endl;
    cout << rect.getPerimeter() << endl;
    cout << tri.getArea() << endl;
    cout << tri.getPerimeter() << endl;
    cout << square.getArea() << endl;
    cout << square.getPerimeter() << endl;
    cout << iso.getArea() << endl;
    cout << iso.getPerimeter() << endl;

    return 0;
}