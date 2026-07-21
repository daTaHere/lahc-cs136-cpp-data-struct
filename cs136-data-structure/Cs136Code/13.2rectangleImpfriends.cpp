#include <iomanip> 
#include <cassert>
#include "13.2RectangleType2.h"

using namespace std;

void rectangleType2 ::setDimension(double l, double w)
{
    if (l >= 0)
        length = l;
    else
        length = 0;

    if (w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType2::getLength() const
{
    return length;
}

double rectangleType2::getWidth()const
{
    return width;
}

double rectangleType2::area() const
{
    return length * width;
}

double rectangleType2::perimeter() const
{
    return 2 * (length + width);
}

rectangleType2::rectangleType2(double l, double w)
{
    setDimension(l, w);
}

rectangleType2::rectangleType2()
{
    length = 0;
    width = 0;
}

rectangleType2& operator++(rectangleType2& rec) {
    //increment the length and width

    double newLength = rec.getLength();
    double newWidth = rec.getLength();
    rec.setDimension(newLength++, newWidth++);

    return rec;   //return the incremented value of the object
}

rectangleType2 operator++(rectangleType2& rec, int u) {
    rectangleType2 temp = rec;  //use this pointer to copy 
    //the value of the object
//increment the length and width
    rec.length += 1;
    rec.width += 1;
    return temp;    //return the old value of the object
}

rectangleType2& operator--(rectangleType2& rec)
{
    //Decrement the length and width
    assert(rec.length != 0 && rec.width != 0);
    --rec.length;
    --rec.width;

    return rec;    //return the incremented value of the object
}

rectangleType2 operator--(rectangleType2& rec, int u)
{
    rectangleType2 temp = rec;  //use this pointer to copy 
    //the value of the object

//Decrement the length and width   
    assert(rec.length != 0 && rec.width != 0);
    --rec.length;
    --rec.width;

    return temp;    //return the old value of the object
}

rectangleType2 operator+ (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    rectangleType2 tempRect;
    tempRect.length = rectangle1.length + rectangle2.length;
    tempRect.width = rectangle1.width + rectangle2.width;

    return tempRect;
}

rectangleType2 operator- (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    rectangleType2 tempRect;

    assert(rectangle1.length >= rectangle2.length && rectangle1.width >= rectangle2.width);

    tempRect.length = rectangle1.length - rectangle2.length;
    tempRect.width = rectangle1.width - rectangle2.width;

    return tempRect;
}

rectangleType2 operator*(const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    rectangleType2 tempRect;

    tempRect.length = rectangle1.length * rectangle2.length;
    tempRect.width = rectangle1.width * rectangle2.width;

    return tempRect;
}

bool operator== (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    return (rectangle1.area() == rectangle2.area());
}

bool operator!= (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    return (rectangle1.area() != rectangle2.area());
}

bool operator<= (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    return (rectangle1.area() <= rectangle2.area());
}

bool operator< (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    return (rectangle1.area() < rectangle2.area());
}

bool operator>= (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    return (rectangle1.area() >= rectangle2.area());
}

bool operator> (const rectangleType2& rectangle1, const rectangleType2& rectangle2)
{
    return (rectangle1.area() > rectangle2.area());
}

ostream& operator<<(ostream& osObject, const rectangleType2& rectangle)
{
    osObject << "Length = " << rectangle.length
        << "; Width = " << rectangle.width;

    return osObject;
}

istream& operator>>(istream& isObject, rectangleType2& rectangle)
{
    isObject >> rectangle.length >> rectangle.width;

    return isObject;
}


// 13e test function
void Test13_2() {
    cout << "=======   13.2 a ( Overload post/pre ++,-- ) w.friends =========\n";
    rectangleType2 myRectangle(23, 45);

    cout << fixed << showpoint << setprecision(2);

    cout << "on Pre fix ++ : ";

    cout << myRectangle++ << endl;

    cout << "on Post fix ++ :";
    cout << ++myRectangle << endl;


    cout << "on Pre fix -- :";
    cout << --myRectangle << endl;


    cout << "on Post fix -- : ";
    cout << myRectangle-- << endl;

    cout << "\n=======   13.1 b ( Overload subtract \"-\") ) =========\n";

    rectangleType2 yourRectangle(10, 12);
    cout << "Test  \"-\" Invalid rectangles\n";
    //rectangleType2 recC = yourRectangle - myRectangle; // Assert breaks here
    //cout << recC << endl;

    cout << "Test  \"-\" Valid rectangles\n";
    rectangleType2 recD = myRectangle - yourRectangle;

    cout << recD << endl;

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

