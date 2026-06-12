#include <iomanip> 
#include "13.2RectangleType2.h"


using namespace std;

// define construtors
RectangleType2 :: RectangleType2() {
    length = 0;
    width = 0;
}
RectangleType2 ::RectangleType2(double l, double w) : length(l), width(w) {}

// define methods
void RectangleType2 :: setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

RectangleType2 RectangleType2 :: doubleDimensions() {
    length *= 2;
    width *= 2;
    return *this;
}


double RectangleType2 :: getLength() const { return length; }
double RectangleType2 :: getWidth() const { return width; }
double RectangleType2 :: area() const { return length * width; }
double RectangleType2 :: perimeter() const { return 2 * (length + width); }
void RectangleType2 :: print() const {
    cout << "Length = " << length << "; Width = " << width;
}

RectangleType2& RectangleType2 :: setLength(const double l) { length = l; return *this; };
RectangleType2& RectangleType2 :: setWidth(const double w) { width = w; return *this; };

// 13.2 friends
RectangleType2& operator++( RectangleType2& a) {
    double newLength = a.getLength();
    double newWidth = a.getWidth();
    a.setDimension(++newLength, ++newWidth);
    return a;
};
RectangleType2 operator++(RectangleType2& a, int) {
    RectangleType2 temp = a;
    ++a;
    return temp;
};

RectangleType2& operator--(RectangleType2& a) {
    double newLength = a.length;
    double newWidth = a.width;
    if ( newLength > 1 and newWidth > 1) {
        --a.length;
        --a.length;
    }
    return a;
};
RectangleType2 operator--(RectangleType2& a , int) {
    RectangleType2 temp = a;
    --(a);
    return temp;
};

//13d define overload operators ( - )
RectangleType2 operator-(const RectangleType2& lhs, const RectangleType2& rhs )  {
    double newLength = lhs.length - rhs.length;
    double newWidth = lhs.width - rhs.width;

    if (newWidth <= 0 || newLength <= 0) {
        cout << "Operation invalid! Resulting dimensions must be positive." << endl;
        return RectangleType2();
    }
    return RectangleType2(newLength, newWidth);
};

//13d define overload operators ( ==, !=, <, <=, >, >= )
bool operator==(const RectangleType2& a, const RectangleType2& b) {
    return a.area() == b.area();
};
bool operator!=(const RectangleType2& a, const RectangleType2& b)  {
    return a.area() != b.area();
};

// 13d friends 
bool operator>(const RectangleType2& a, const RectangleType2& b) {
    return a.area() > b.area();
};
bool operator>=(const RectangleType2& a, const RectangleType2& b) {
    return a.area() >= b.area();
};
bool operator<(const RectangleType2& a, const RectangleType2& b) {
    return a.area() < b.area();
};
bool operator<=(const RectangleType2& a, const RectangleType2& b) {
    return a.area() <= b.area();
};


// 13e test function
void Test13_2() {
    cout << "=======   13.2 a ( Overload post/pre ++,-- ) w.friends =========\n";
    RectangleType2 myRectangle(23, 45);

    cout << fixed << showpoint << setprecision(2);

    cout << "on Pre fix ++ : ";
    myRectangle++.print();
    cout << endl;

    cout << "on Post fix ++ :";
    ++myRectangle;
    myRectangle.print();
    cout << endl;

    cout << "on Pre fix -- :";
    --myRectangle;
    myRectangle.print();
    cout << endl;

    cout << "on Post fix -- : ";
    myRectangle--.print();
    cout << "\n" << endl;

    cout << "\n=======   13.1 b ( Overload subtract \"-\") ) =========\n";
 
    RectangleType2 yourRectangle(10, 12);
    cout << "Test  \"-\" Invalid rectangles\n";
    RectangleType2 recC = yourRectangle - myRectangle;
    recC.print();

    cout << "Test  \"-\" Valid rectangles\n";
    RectangleType2 recD = myRectangle - yourRectangle;
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

