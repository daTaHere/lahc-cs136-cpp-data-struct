#include <iostream> 
#include <iomanip> 
#include "13.1RectangleType.h"


using namespace std;

// define construtors
RectangleType :: RectangleType()  {
	length = 0;
	width = 0;
}
RectangleType :: RectangleType( double l, double w) : length(l), width(w) {}

// define methods
void RectangleType :: setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

RectangleType RectangleType :: doubleDimensions() {
    length *= 2;
    width *= 2;
    return *this;
}


double RectangleType :: getLength() const { return length; }
double RectangleType :: getWidth() const { return width; }
double RectangleType :: area() const { return length * width; }
double RectangleType :: perimeter() const { return 2 * (length + width); }
void RectangleType :: print() const {
    cout << "Length = " << length << "; Width = " << width;
}


RectangleType& RectangleType :: setLength(const double l) { length = l; return *this; };
RectangleType& RectangleType :: setWidth(const double w) { width = w; return *this; };

// 13d define overload operators pre/post (++, --)
RectangleType& RectangleType :: operator++() {
    length++;
    width++;
    return *this;
};
RectangleType RectangleType :: operator++(int) {
    RectangleType temp = *this;
    ++(*this);
    return temp;
};

RectangleType& RectangleType :: operator--() {
    if (length > 1 and width > 1) {
        length--;
        width--;
    }
    return *this;
};
RectangleType RectangleType :: operator--(int) {
    RectangleType temp = *this;
    --(*this);
    return temp;
};

//13d define overload operators ( - )
RectangleType RectangleType :: operator-(const RectangleType& other) const {
    double newLength = this->length - other.length;
    double newWidth = this->width - other.width;

    if (newWidth <= 0 || newLength <= 0) {
        cout << "Operation invalid! Resulting dimensions must be positive." << endl;
        return RectangleType();
    }
    return RectangleType(newLength, newWidth);
};

//13d define overload operators ( ==, !=, <, <=, >, >= )
bool RectangleType :: operator==(const RectangleType& other) const {
    return this->area() == other.area();
};
bool RectangleType :: operator!=(const RectangleType& other) const {
    return this->area() != other.area();
};

// 13d friends 
bool RectangleType :: operator>(const RectangleType& a) const  {
    return this->area() > a.area();
};
bool RectangleType :: operator>=(const RectangleType& a) const {
    return this->area() >= a.area();
};
bool RectangleType :: operator<(const RectangleType& a) const {
    return this->area() < a.area();
};
bool RectangleType :: operator<=(const RectangleType& a) const {
    return (*this).area() <= a.area();
};


// 13e test function
void Test13_1() {
    cout << "=======   13.1 a ( Overload post/pre ++,-- ) =========\n";
    RectangleType myRectangle(23, 45);
    
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

    RectangleType yourRectangle(10, 12);
    cout << "Test  \"-\" Invalid rectangles\n";
    RectangleType recC = yourRectangle - myRectangle;
    recC.print();

    cout << "Test  \"-\" Valid rectangles\n";
    RectangleType recD = myRectangle - yourRectangle;
    recD.print();
    cout << endl;

    cout << "\n=======   13.1 c ( Overload  \"== \", \"!= \" ) ) =========\n";
    cout << "+++  myRectangle Area: " << myRectangle.area() << endl;
    cout << "+++ yourRectangle: " << yourRectangle.area() << endl;;

    cout << "\n-------     test ==  ------" << endl;
    cout << "( myRectangle == yourRectangle ) = " << ((myRectangle == yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( myRectangle == myRectangle ) = " << ((myRectangle == myRectangle) != 0 ? "True" : "False") << endl;

    cout << "\n-------     test !=  ------" << endl;
    cout << "( myRectangle != yourRectangle ) = " << ((myRectangle != yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle != yourRectangle ) = " << ((yourRectangle != yourRectangle) != 0 ? "True" : "False") << endl;

    cout << "\n=======   13.1 c ( Overload  friend funct ) =========\n";
    cout << "\n-------     test >  ------" << endl;
    cout << "( myRectangle > yourRectangle ) = " << ((myRectangle > yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle > myRectangle ) = " << ((yourRectangle > myRectangle) != 0 ? "True" : "False") << endl;
    cout << "( myRectangle > myRectangle ) = " << ((myRectangle > myRectangle) != 0 ? "True" : "False") << endl;

    cout << "\n-------     test >=  ------" << endl;
    cout << "( myRectangle >= yourRectangle ) = " << ((myRectangle >= yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle >= myRectangle ) = " << ((yourRectangle >= myRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle >= yourRectangle ) = " << ((yourRectangle >= yourRectangle) != 0 ? "True" : "False") << endl;

    cout << "\n-------     test <   ------" << endl;
    cout << "( myRectangle < yourRectangle ) = " << ((myRectangle < yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle < meRectangle ) = " << ((yourRectangle < myRectangle) != 0 ? "True" : "False") << endl;
    cout << "( yourRectangle < yourRectangle ) = " << ((yourRectangle < yourRectangle) != 0 ? "True" : "False") << endl;

    cout << "\n-------     test <=   ------" << endl;
    cout << "( myRectangle <= yourRectangle ) = " << ((myRectangle <= yourRectangle) != 0 ? "True" : "False") << endl;
    cout << "( myRectangle <= yourRectangle ) = " << ((yourRectangle <= myRectangle) != 0 ? "True" : "False") << endl;
    cout << "( myRectangle <= myRectangle ) = " << ((myRectangle <= myRectangle) != 0 ? "True" : "False") << endl;
}

