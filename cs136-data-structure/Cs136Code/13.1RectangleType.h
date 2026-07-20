#pragma once
#include <iostream>

class rectangleType {


protected:
    double length;
    double width;


public:
    rectangleType();
    rectangleType(double l, double w);

    void setDimension(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;

    rectangleType operator+(const rectangleType&) const;
    rectangleType operator*(const rectangleType&) const;
    rectangleType operator-(const rectangleType&) const;

    rectangleType operator++();      // pre-increment
    rectangleType operator++(int);   // post-increment
    rectangleType operator--();      // pre-decrement
    rectangleType operator--(int);   // post-decrement

    bool operator==(const rectangleType&) const;
    bool operator!=(const rectangleType&) const;
    bool operator<(const rectangleType&) const;
    bool operator<=(const rectangleType&) const;
    bool operator>(const rectangleType&) const;
    bool operator>=(const rectangleType&) const;


    friend std::ostream& operator<<(std::ostream&, const rectangleType&);
    friend std::istream& operator>>(std::istream&, rectangleType&);

};