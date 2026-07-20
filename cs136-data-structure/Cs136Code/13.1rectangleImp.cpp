#include <iostream> 
#include <iomanip> 
#include "13.1RectangleType.h"

using namespace std;

rectangleType::rectangleType() {
    length = 0;
    width = 0;
}

rectangleType::rectangleType(double l, double w) {
    setDimension(l, w);
}

void rectangleType::setDimension(double l, double w) {
    length = (l >= 0) ? l : 0;
    width = (w >= 0) ? w : 0;
}

double rectangleType::getLength() const {
    return length;
}

double rectangleType::getWidth() const {
    return width;
}

double rectangleType::area() const {
    return length * width;
}

double rectangleType::perimeter() const {
    return 2 * (length + width);
}

rectangleType rectangleType::operator+(const rectangleType& rectangle) const {
    return rectangleType(length + rectangle.length,
        width + rectangle.width);
}

rectangleType rectangleType::operator*(const rectangleType& rectangle) const {
    return rectangleType(length * rectangle.length,
        width * rectangle.width);
}

rectangleType rectangleType::operator-(const rectangleType& rectangle) const {
    double newLength = length - rectangle.length;
    double newWidth = width - rectangle.width;

    if (newLength <= 0 || newWidth <= 0) {
        cout << "Operation invalid. Resulting dimensions must be positive."
            << endl;
        return *this;
    }

    return rectangleType(newLength, newWidth);
}

rectangleType rectangleType::operator++() {
    ++length;
    ++width;
    return *this;
}

rectangleType rectangleType::operator++(int) {
    rectangleType temp = *this;
    ++length;
    ++width;
    return temp;
}

rectangleType rectangleType::operator--() {
    if (length - 1 > 0 && width - 1 > 0) {
        --length;
        --width;
    }
    else {
        cout << "Operation invalid. Dimensions must remain positive."
            << endl;
    }

    return *this;
}

rectangleType rectangleType::operator--(int) {
    rectangleType temp = *this;

    if (length - 1 > 0 && width - 1 > 0) {
        --length;
        --width;
    }
    else {
        cout << "Operation invalid. Dimensions must remain positive."
            << endl;
    }

    return temp;
}

bool rectangleType::operator==(const rectangleType& rectangle) const {
    return area() == rectangle.area();
}

bool rectangleType::operator!=(const rectangleType& rectangle) const {
    return area() != rectangle.area();
}

bool rectangleType::operator<(const rectangleType& rectangle) const {
    return area() < rectangle.area();
}

bool rectangleType::operator<=(const rectangleType& rectangle) const {
    return area() <= rectangle.area();
}

bool rectangleType::operator>(const rectangleType& rectangle) const {
    return area() > rectangle.area();
}

bool rectangleType::operator>=(const rectangleType& rectangle) const {
    return area() >= rectangle.area();
}

ostream& operator<<(ostream& output, const rectangleType& rectangle) {
    output << "Length = " << rectangle.length
        << "; Width = " << rectangle.width;

    return output;
}

istream& operator>>(istream& input, rectangleType& rectangle) {
    double l;
    double w;

    input >> l >> w;

    if (input)
        rectangle.setDimension(l, w);

    return input;
}

// 13e test function
void Test13_1() {
    rectangleType yard1(5, 3);
    rectangleType yard2(4, 7);

    cout << yard1 << endl;
    cout << yard1-- << endl;
    cout << yard1 << endl;
    cout << --yard1 << endl;

    cout << (yard1 == yard2 ? "true" : "false") << endl;

    cout << (yard1 != yard2 ? "true" : "false") << endl;

    cout << (yard2 == yard2 ? "true" : "false") << endl;

    cout << (yard2 != yard2 ? "true" : "false") << endl;

    cout << yard2 << endl;

    cout << ++yard2 << endl;
    cout << yard2++ << endl;

    cout << yard2 << endl;

    cout << yard1 * yard2 << endl;

    rectangleType yard3(1, 1);
    cout << --yard3 << endl;

    cout << endl << (yard3 - yard2) << endl;
}

