//personTypeImp.cpp

#include <iostream>
#include <string>
#include "21.3personType.h"

using namespace std;

void personType2::print() const
{
	cout << firstName << " " << lastName;
}

void personType2::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

string personType2::getFirstName() const
{
	return firstName;
}

string personType2::getLastName() const
{
	return lastName;
}

personType2::personType2(string first, string last)

{
	firstName = first;
	lastName = last;
}

bool personType2::operator==(const personType2& right) const
{
	return(firstName == right.firstName &&
		lastName == right.lastName);
}

bool personType2::operator!=(const personType2& right) const
{
	return(firstName != right.firstName ||
		lastName != right.lastName);
}

bool personType2::operator<=(const personType2& right) const
{
	return(*this < right || *this == right);
}

bool personType2::operator<(const personType2& right) const
{
	return((lastName < right.lastName) ||
		(lastName == right.lastName &&
			firstName < right.firstName));
}

bool personType2::operator>=(const personType2& right) const
{
	return(*this > right || *this == right);
}

bool personType2::operator>(const personType2& right) const
{
	return((lastName > right.lastName) ||
		(lastName == right.lastName &&
			firstName > right.firstName));
}