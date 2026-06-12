#pragma once
#include <iostream>

using namespace std;


class RectangleType2 {

protected:
    double length;
    double width;

public:
    // Constructors
    RectangleType2();
    RectangleType2(double l, double w);

    // Methods
    void setDimension(double l, double w);
    RectangleType2 doubleDimensions();
    RectangleType2& setLength(const double l);
    RectangleType2& setWidth(const double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;


    //  Programming Exercise 13-1a
    friend RectangleType2& operator++( RectangleType2& a );
    friend RectangleType2  operator++(  RectangleType2& a, int);
    friend RectangleType2&  operator--( RectangleType2& a);
    friend RectangleType2  operator--(  RectangleType2& a, int);

    //  Programming Exercise 13-1b
    friend RectangleType2 operator-(const RectangleType2& lhs, const RectangleType2& rhs);


    //  Programming Exercise 13-1b
    friend bool  operator==(const RectangleType2&, const RectangleType2& b) ;
    friend bool  operator!=(const RectangleType2&, const RectangleType2& b) ;
    friend  bool  operator>(const RectangleType2& a, const RectangleType2& b);
    friend bool  operator>=(const RectangleType2& a, const RectangleType2& b);
    friend bool  operator<(const RectangleType2& a, const RectangleType2& b);
    friend bool  operator<=(const RectangleType2& a, const RectangleType2& b);
};
