#include <cmath>
#include <iomanip> 
#include "13.7ComplexType.h"

ostream& operator<< (ostream& os, const complexType& complex)
{
	os << "(" << complex.realPart << ", "
		<< complex.imaginaryPart << ")";
	return os;
}

istream& operator>> (istream& is, complexType& complex)
{
	char ch;

	is >> ch;                     //read and discard (
	is >> complex.realPart;       //get the real part
	is >> ch;                     //read and discard,
	is >> complex.imaginaryPart;  //get the imaginary part
	is >> ch;                     //read and discard)

	return is;
}

bool complexType::operator==(const complexType& otherComplex) const
{
	return(realPart == otherComplex.realPart &&
		imaginaryPart == otherComplex.imaginaryPart);
}

//constructor
complexType::complexType(double real, double imag)
{
	realPart = real;
	imaginaryPart = imag;
}

void complexType::setComplex(const double& real, const double& imag)
{
	realPart = real;
	imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const
{
	real = realPart;
	imag = imaginaryPart;
}

//overload the operator +
complexType complexType::operator+(const complexType& otherComplex) const
{
	complexType temp;

	temp.realPart = realPart + otherComplex.realPart;
	temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

	return temp;
}

//overload the operator *
complexType complexType::operator*(const complexType& otherComplex) const
{
	complexType temp;

	temp.realPart = (realPart * otherComplex.realPart) -
		(imaginaryPart * otherComplex.imaginaryPart);
	temp.imaginaryPart = (realPart * otherComplex.imaginaryPart) +
		(imaginaryPart * otherComplex.realPart);
	return temp;
}

// overload the operator -
complexType complexType::operator-(const complexType& otherComplex) const {
	complexType temp;
	temp.realPart = (this->realPart - otherComplex.realPart);
	temp.imaginaryPart = (this->imaginaryPart - otherComplex.imaginaryPart);

	return temp;
};
// overload the oeprator /
complexType complexType::operator/(const complexType& otherComplex) const {

	complexType temp;

	double c = otherComplex.realPart;
	double d = otherComplex.imaginaryPart;
	double divisor = (c * c) + (d * d);

	if (int(divisor) == 0) {
		cout << "Divide by 0 error" << endl;
		return temp;
	}


	double a = this->realPart;
	double b = this->imaginaryPart;

	temp.realPart = (a * c + b * d) / divisor;
	temp.imaginaryPart = (-1 * (a * d) + b * c) / divisor;

	return temp;
};



void Test13_7() {
    cout << "=======   13.7 ( 7ComplexType ) =========\n";
	complexType a(5.00, 6.00);
	complexType b(8.00, 0.00);

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a == b: " << (a == b ? "True" : "False" ) << endl;
}

