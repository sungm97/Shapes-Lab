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
    private:
        double width;
        double length;
    public:
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

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle(double r)
        {
            radius = r;
        }
        double getArea() override
        {
            return 2 * 3.14 * pow(radius, 2);
        }
        double getPerimeter() override
        {
            return 2 * 3.14 * radius;
        }
};

class RightTriangle : public Shape
{
    private:
        double height;
        double base;
    public:
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

int main()
{
    Rectangle rect(5.0, 6.0);
    RightTriangle tri(8.0, 15.0);

    Circle circle(5.0);

    cout << circle.getArea() << endl;
    cout << circle.getPerimeter() << endl;

    cout << rect.getArea() << endl;
    cout << rect.getPerimeter() << endl;
    cout << tri.getArea() << endl;
    cout << tri.getPerimeter() << endl;

    return 0;
}