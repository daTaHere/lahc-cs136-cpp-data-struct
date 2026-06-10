#pragma once
#include <iostream>

using namespace std;


class rectangleType2 {

protected:
    double length;
    double width;

public:
    // Constructors
    rectangleType2();
    rectangleType2(double l, double w);

    // Methods
    void setDimension(double l, double w);
    rectangleType2 doubleDimensions();
    rectangleType2& setLength(const double l);
    rectangleType2& setWidth(const double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;


    //  Programming Exercise 13-1a
    friend rectangleType2& operator++( rectangleType2& a );
    friend rectangleType2  operator++(  rectangleType2& a, int);
    friend rectangleType2&  operator--( rectangleType2& a);
    friend rectangleType2  operator--(  rectangleType2& a, int);

    //  Programming Exercise 13-1b
    friend rectangleType2 operator-(const rectangleType2& lhs, const rectangleType2& rhs);


    //  Programming Exercise 13-1b
    friend bool  operator==(const rectangleType2&, const rectangleType2& b) ;
    friend bool  operator!=(const rectangleType2&, const rectangleType2& b) ;
    friend  bool  operator>(const rectangleType2& a, const rectangleType2& b);
    friend bool  operator>=(const rectangleType2& a, const rectangleType2& b);
    friend bool  operator<(const rectangleType2& a, const rectangleType2& b);
    friend bool  operator<=(const rectangleType2& a, const rectangleType2& b);
};
