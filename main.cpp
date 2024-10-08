#include <iostream>
#include <cassert>

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

int main()
{
    Rectangle rect(5.0, 6.0);
    cout << rect.getArea() << endl;
    cout << rect.getPerimeter() << endl;

    return 0;
}