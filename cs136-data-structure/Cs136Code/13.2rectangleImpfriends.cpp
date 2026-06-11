#include <iostream> 
#include <iomanip> 
#include <string>
#include "13.2RectangleType2.h"


using namespace std;

// define construtors
rectangleType2 :: rectangleType2() {
    length = 0;
    width = 0;
}
rectangleType2 ::rectangleType2(double l, double w) : length(l), width(w) {}

// define methods
void rectangleType2 :: setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

rectangleType2 rectangleType2 :: doubleDimensions() {
    length *= 2;
    width *= 2;
    return *this;
}


double rectangleType2 :: getLength() const { return length; }
double rectangleType2 :: getWidth() const { return width; }
double rectangleType2 :: area() const { return length * width; }
double rectangleType2 :: perimeter() const { return 2 * (length + width); }
void rectangleType2 :: print() const {
    cout << "Length = " << length << "; Width = " << width;
}

rectangleType2& rectangleType2 :: setLength(const double l) { length = l; return *this; };
rectangleType2& rectangleType2 :: setWidth(const double w) { width = w; return *this; };

// 13.2 friends
rectangleType2& operator++( rectangleType2& a) {
    double newLength = a.getLength();
    double newWidth = a.getWidth();
    a.setDimension(++newLength, ++newWidth);
    return a;
};
rectangleType2 operator++(rectangleType2& a, int) {
    rectangleType2 temp = a;
    ++a;
    return temp;
};

rectangleType2& operator--(rectangleType2& a) {
    double newLength = a.length;
    double newWidth = a.width;
    if ( newLength > 1 and newWidth > 1) {
        --a.length;
        --a.length;
    }
    return a;
};
rectangleType2 operator--(rectangleType2& a , int) {
    rectangleType2 temp = a;
    --(a);
    return temp;
};

//13d define overload operators ( - )
rectangleType2 operator-(const rectangleType2& lhs, const rectangleType2& rhs )  {
    double newLength = lhs.length - rhs.length;
    double newWidth = lhs.width - rhs.width;

    if (newWidth <= 0 || newLength <= 0) {
        cout << "Operation invalid! Resulting dimensions must be positive." << endl;
        return rectangleType2();
    }
    return rectangleType2(newLength, newWidth);
};

//13d define overload operators ( ==, !=, <, <=, >, >= )
bool operator==(const rectangleType2& a, const rectangleType2& b) {
    return a.area() == b.area();
};
bool operator!=(const rectangleType2& a, const rectangleType2& b)  {
    return a.area() != b.area();
};

// 13d friends 
bool operator>(const rectangleType2& a, const rectangleType2& b) {
    return a.area() > b.area();
};
bool operator>=(const rectangleType2& a, const rectangleType2& b) {
    return a.area() >= b.area();
};
bool operator<(const rectangleType2& a, const rectangleType2& b) {
    return a.area() < b.area();
};
bool operator<=(const rectangleType2& a, const rectangleType2& b) {
    return a.area() <= b.area();
};


// 13e test function
void Test13_2() {
    cout << "=======   13.2 a ( Overload post/pre ++,-- ) w.friends =========\n";
    rectangleType2 myRectangle(23, 45);

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
 
    rectangleType2 yourRectangle(10, 12);
    cout << "Test  \"-\" Invalid rectangles\n";
    rectangleType2 recC = yourRectangle - myRectangle;
    recC.print();

    cout << "Test  \"-\" Valid rectangles\n";
    rectangleType2 recD = myRectangle - yourRectangle;
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

