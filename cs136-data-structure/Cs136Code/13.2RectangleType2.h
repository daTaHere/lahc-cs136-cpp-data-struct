#pragma once
#include <iostream>

using namespace std;
class rectangleType2
{
    //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const rectangleType2&);
    friend istream& operator>>(istream&, rectangleType2&);

public:
    void setDimension(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;

    //Overload the arithmetic operators
    friend rectangleType2 operator + (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend rectangleType2 operator - (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend rectangleType2 operator * (const rectangleType2& rectangle1, const rectangleType2& rectangle2);

    //Overload the increment and decrement operators
    friend rectangleType2& operator ++ (rectangleType2& rhs);          //pre-increment
    friend rectangleType2 operator ++ (rectangleType2& rhs, int u);       //post-increment
    friend rectangleType2& operator -- (rectangleType2& rhs);          //pre-decrement
    friend rectangleType2 operator -- (rectangleType2& rhs, int u);       //post-decrement

    //Overload the relational operators
    friend bool operator == (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend bool operator != (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend bool operator <= (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend bool operator < (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend bool operator >= (const rectangleType2& rectangle1, const rectangleType2& rectangle2);
    friend bool operator > (const rectangleType2& rectangle1, const rectangleType2& rectangle2);

    //constructors
    rectangleType2();
    rectangleType2(double l, double w);

protected:
    double length;
    double width;
};
