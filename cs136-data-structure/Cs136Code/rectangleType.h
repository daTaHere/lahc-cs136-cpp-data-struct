#include <iostream>

using namespace std;

class rectangleType {

protected:
    double length;
    double width;

public:
    // Constructors
    rectangleType();
    rectangleType(double l, double w);

    void setDimension(double l, double w);
    rectangleType doubleDimensions();
    rectangleType& setLength(const double l);
    rectangleType& setWidth(const double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;
    rectangleType operator+(const rectangleType&) const;
    //Overload the operator +
    rectangleType operator*(const rectangleType&) const;
    //Overload the operator *
    bool operator==(const rectangleType&) const;
    //Overload the operator ==
    bool operator!=(const rectangleType&) const;
    //Overload the operator !=


};