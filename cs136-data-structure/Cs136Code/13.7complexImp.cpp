#include <cmath>
#include <iomanip> 
#include "13.7ComplexType.h"

ComplexType :: ComplexType(double real, double imag) : 
	realPart(real), imaginaryPart(imag) {};

void ComplexType :: setComplex(const double& real, const double& imag) {
	realPart = real;
	imaginaryPart = imag;
};

void ComplexType :: getComplex(double& real, double& imag) const {
    real = realPart;
    imag = imaginaryPart;
}

// member overload operators
ComplexType ComplexType :: operator+ (const ComplexType& other) const {
    ComplexType sum;
    sum.realPart = realPart + other.realPart;
    sum.imaginaryPart = imaginaryPart + other.imaginaryPart;
    return sum;
};

ComplexType ComplexType :: operator* (const ComplexType& other) const {
    ComplexType prod;
    double ac = realPart * other.realPart;
    double bd = imaginaryPart * other.imaginaryPart;
    prod.realPart = ac - bd;

    double ad = realPart * other.imaginaryPart;
    double bc = imaginaryPart * other.realPart;
    prod.imaginaryPart = ad + bc;
    
    return prod;
};

bool ComplexType :: operator== (const ComplexType& other) const {
    return (realPart == other.realPart && imaginaryPart == other.imaginaryPart);
}

// friend overload operator 
ostream& operator<<(ostream& out, const ComplexType& lhs) {
    out << "("  << lhs.realPart << ", " << lhs.imaginaryPart << ")";
    return out;
};
istream& operator>>(istream& in, ComplexType& lhs) {
    char ch;
    in >> ch >> lhs.realPart; 
    in >> ch >> lhs.imaginaryPart;
    in >> ch;
    return in;
};

//  ========  13.7 overload operator ( -, / )  ==========================
ComplexType ComplexType :: operator- (const ComplexType& other) const {
    ComplexType diff;
    diff.realPart = realPart - other.realPart;
    diff.imaginaryPart = imaginaryPart - other.imaginaryPart;
    return diff;
};

ComplexType ComplexType :: operator/ (const ComplexType& other) const {
    double a = realPart;
    double b = imaginaryPart;
    double c = other.realPart;
    double d = other.imaginaryPart;
    ComplexType quotient;
    if (c != 0 || d != 0) {
        double donaminator = (c * c) + (d * d);
        quotient.realPart = (a * c + b * d) / donaminator;
        quotient.imaginaryPart = (-1 * (a * d) + (b * c)) / donaminator;

        return quotient;
    }
    cout << "Invalid operation, divide by 0 violation!\n" << endl;
    return quotient;
};


void Test13_7() {
    cout << "=======   13.7 ( 7ComplexType ) =========\n";
    cout << fixed << showpoint << setprecision(2);

    ComplexType num1(21, 18);
    ComplexType num2;
    ComplexType num3;
    cout << "Num1 = " << num1 << endl;
    cout << "Num2 = " << num2 << endl;

    cout << "Enter a complex number " << "in the form (a, b): ";
    cin >> num2;
    cout << endl;
    cout << "New value of num2 = " << num2 << endl;
    num3 = num1 + num2;

    cout << "Num3 = " << num3 << endl;
    cout <<  num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout <<  num1 << " * " << num2 << " = " << num1 * num2 << endl;

    cout << "\n-------     test ==  ------" << endl;
    cout << "( num1 == num1 ) = " << ((num1 == num1) != 0 ? "True" : "False") << endl;
    cout << "( num1 == num2 ) = " << ((num1 == num2) != 0 ? "True" : "False") << endl;


    // 13.7 test  ============================
    cout << "\n-------     test  -  ------" << endl;
    cout << "( num1 - num1 ) = " << (num1 - num1) << endl;
    cout << "( num1 - num2 ) = " << (num1 - num2) << endl;

    cout << "\n-------     test  /  ------" << endl;
    cout << "( num1/num2 ) = " << (num1/ num2) << endl;

    ComplexType zeros;
    cout << "( num1/zeros ) = " << (num1 / zeros) << endl;
}

