#pragma once
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

    // Methods
    void setDimension(double l, double w);
    rectangleType doubleDimensions();
    rectangleType& setLength(const double l);
    rectangleType& setWidth(const double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;

    //Overload the operators
    rectangleType operator+(const rectangleType&) const;
    rectangleType operator*(const rectangleType&) const;
    bool operator==(const rectangleType&) const;
    bool operator!=(const rectangleType&) const;

    //  Programming Exercise 13-1a
    rectangleType& operator++();
    rectangleType operator++(int);
    rectangleType& operator--();
    rectangleType operator--(int);

    //  Programming Exercise 13-1b
    rectangleType operator-(const rectangleType&) const;



};
