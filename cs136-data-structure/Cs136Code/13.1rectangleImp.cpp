#include <iostream> 
#include <iomanip> 
#include <string>
#include "13.1rectangleType.h"


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

// 13d define overload operators pre/post (++, --)
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
    if (length > 1 and width > 1) {
        length--;
        width--;
    }
    return *this;
};
rectangleType rectangleType :: operator--(int) {
    rectangleType temp = *this;
    --(*this);
    return temp;
};

//13d define overload operators ( - )
rectangleType rectangleType :: operator-(const rectangleType& other) const {
    double newLength = this->length - other.length;
    double newWidth = this->width - other.width;

    if (newWidth <= 0 || newLength <= 0) {
        cout << "Operation invalid! Resulting dimensions must be positive." << endl;
        return rectangleType();
    }
    return rectangleType(newLength, newWidth);
};

//13d define overload operators ( ==, !=, <, <=, >, >= )
bool rectangleType :: operator==(const rectangleType& other) const {
    return this->area() == other.area();
};
bool rectangleType :: operator!=(const rectangleType& other) const {
    return this->area() != other.area();
};

// 13d friends 
bool operator>(const rectangleType& a, const rectangleType& b )  {
    return a.area() > b.area();
};
bool operator>=(const rectangleType& a, const rectangleType& b) {
    return a.area() >= b.area();
};
bool operator<(const rectangleType& a, const rectangleType& b) {
    return a.area() < b.area();
};
bool operator<=(const rectangleType& a, const rectangleType& b) {
    return a.area() <= b.area();
};


// 13e test function
void Test13_1() {
    cout << "=======   13.1 a ( Overload post/pre ++,-- ) =========\n";
    rectangleType myRectangle(23, 45);
    
    cout << fixed << showpoint << setprecision(2);

    cout << "on post fix ++ : ";
    myRectangle++.print();
    cout << endl;

    cout << "on pre fix ++ :";
    ++myRectangle;
    myRectangle.print();
    cout << endl;

    cout << "on post fix -- :";
    --myRectangle;
    myRectangle.print();
    cout << endl;

    cout << "on pre fix -- : ";
    myRectangle--.print();
    cout << "\n" << endl;

    cout << "\n=======   13.1 b ( Overload subtract \"-\") ) =========\n";

    rectangleType yourRectangle(10, 12);
    cout << "Test  \"-\" Invalid rectangles\n";
    rectangleType recC = yourRectangle - myRectangle;
    recC.print();

    cout << "Test  \"-\" Valid rectangles\n";
    rectangleType recD = myRectangle - yourRectangle;
    recD.print();
    cout << endl;

    cout << "\n=======   13.1 c ( Overload  \"== \", \"!= \" ) ) =========\n";
    cout << "( myRectangle == recB ) = " << ((myRectangle == yourRectangle) != 0 ? "True": "False") << endl;
    
    cout << "( myRectangle != recB ) = " << ((myRectangle != yourRectangle) != 0 ? "True" : "False") << endl;

    cout << "\n=======   13.1 c ( Overload  friend funct ) =========\n";
    cout << "( myRectangle > recB ) = " << ((myRectangle > yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( myRectangle >= recB ) = " << ((myRectangle >= yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( myRectangle < recB ) = " << ((myRectangle < yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle <= myRectangle ) = " << ((yourRectangle <= myRectangle) != 0 ? "True" : "False") << endl;
}

