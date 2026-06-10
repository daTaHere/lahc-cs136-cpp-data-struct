#include <iostream> 
#include <iomanip> 
#include "rectangleType.h"

using namespace std;

rectangleType :: rectangleType()  {
	length = 0;
	width = 0;
}

rectangleType :: rectangleType( double l = 0, double w = 0) : length(l), width(w) {}

void rectangleType::setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

rectangleType rectangleType ::doubleDimensions() {
    length *= 2;
    width *= 2;
    return *this;
}

double rectangleType::getLength() const { return length; }
double rectangleType::getWidth() const { return width; }
double rectangleType::area() const { return length * width; }
double rectangleType::perimeter() const { return 2 * (length + width); }
void rectangleType::print() const {
    cout << "Length = " << length << "; Width = " << width;
}

rectangleType& rectangleType::setLength(const double l) { length = l; return *this; };
rectangleType& rectangleType::setWidth(const double w) { width = w; return *this; };

