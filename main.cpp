#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class Shape
{
    public:
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
        virtual string getName() = 0;

};
string printAreaToScreen(Shape *s)
{
    return "The shape is a " + s->getName() + ". The area of the " + s->getName() + " is " + to_string(s->getArea());
}
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
        string getName() override
        {
            return "Rectangle";
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
        string getName() override
        {
            return "Right Triangle";
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
        string getName() override
        {
            return "Square";
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
        string getName() override
        {
            return "Isoceles Right Triangle";
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
    cout << printAreaToScreen(&rect) << endl;
    cout << printAreaToScreen(&tri) << endl;
    cout << printAreaToScreen(&square) << endl;
    cout << printAreaToScreen(&iso) << endl;


    return 0;
}