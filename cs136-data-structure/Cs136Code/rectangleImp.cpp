#include <iostream> 
#include <iomanip> 
#include "rectangleType.h"

using namespace std;

// define construtors
rectangleType :: rectangleType()  {
	length = 0;
	width = 0;
}
rectangleType :: rectangleType( double l, double w) : length(l), width(w) {}

// define methods
void rectangleType :: setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

rectangleType rectangleType :: doubleDimensions() {
    length *= 2;
    width *= 2;
    return *this;
}


double rectangleType :: getLength() const { return length; }
double rectangleType :: getWidth() const { return width; }
double rectangleType :: area() const { return length * width; }
double rectangleType :: perimeter() const { return 2 * (length + width); }
void rectangleType :: print() const {
    cout << "Length = " << length << "; Width = " << width;
}


rectangleType& rectangleType :: setLength(const double l) { length = l; return *this; };
rectangleType& rectangleType :: setWidth(const double w) { width = w; return *this; };

// define overload operators
rectangleType& rectangleType :: operator++() {
    length++;
    width++;
    return *this;
};
rectangleType rectangleType :: operator++(int) {
    rectangleType temp = *this;
    length++;
    width++;
    return temp;
};

rectangleType& rectangleType :: operator--() {
    length--;
    width--;
    return *this;
};
rectangleType rectangleType :: operator--(int) {
    rectangleType temp = *this;
    length--;
    width--;
    return temp;
};

// define overload operators
rectangleType rectangleType :: operator-(const rectangleType& other) const {
    if (this->length > other.length && this->width > other.width) {
        rectangleType result(this->length - other.length, this->length - other.width);
        return result;
    }
    else {
        cout << "Operation in valid !!! " << endl;
    }
        
};






void Test13_1() {
    cout << "=======   13.1 a ( Overload post/pre ++,-- ) =========\n";
    rectangleType recA(1.2,1.5);
    
    cout << fixed << showpoint << setprecision(2);

    cout << "on pre fix ++ : ";
    recA++.print();
    cout << endl;

    cout << "on post fix ++ :";
    ++recA;
    recA.print();
    cout << endl;

    cout << "on post fix -- :";
    --recA;
    recA.print();
    cout << endl;

    cout << "on pre fix -- : ";
    recA--.print();
    cout << "\n" << endl;

    cout << "=======   13.1 b ( Overload subtract \"-\") ) =========\n";

    rectangleType recB(10, 12);
    cout << "Test  \"-\" Valid rectangles\n";
    rectangleType recC = recB - recA;
    recC.print();

    cout << "Test  \"-\" Valid rectangles\n";
    rectangleType recD = recA - recB;
    recD.print();
    cout << endl;

}

