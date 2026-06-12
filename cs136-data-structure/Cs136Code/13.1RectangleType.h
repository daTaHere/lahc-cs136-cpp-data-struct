#pragma once
using namespace std;

class RectangleType {

protected:
    double length;
    double width;

public:
    // Constructors
    RectangleType();
    RectangleType(double l, double w);

    // Methods
    void setDimension(double l, double w);
    RectangleType doubleDimensions();
    RectangleType& setLength(const double l);
    RectangleType& setWidth(const double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;

    //Overload the operators
    RectangleType operator+(const RectangleType&) const;
    RectangleType operator*(const RectangleType&) const;

    //  Programming Exercise 13-1a
    RectangleType& operator++();
    RectangleType operator++(int);
    RectangleType& operator--();
    RectangleType operator--(int);

    //  Programming Exercise 13-1b
    RectangleType operator-(const RectangleType&) const;


    //  Programming Exercise 13-1b
    bool operator==(const RectangleType&) const;
    bool operator!=(const RectangleType&) const;
    bool  operator>(const RectangleType& a) const;
    bool  operator>=(const RectangleType& a) const;
    bool  operator<(const RectangleType& a) const;
    bool  operator<=(const RectangleType& a) const;
};
