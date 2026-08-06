#include <iostream> 
#include <list>
#include <algorithm>
#include <iterator>

#include "21.3customer.h"

using namespace std;

void customerType::print()
{
	cout << custAcctNo << " ";
	personType2::print();
	cout << " " << rentedVideoList.size() << endl;
}

void customerType::setCustInfo(string first, string last, int acctNo)
{
	setName(first, last);
	custAcctNo = acctNo;
}

void customerType::rentVideo(string title)
{
	rentedVideoList.push_front(title);
}

void customerType::returnVideo(string title)
{
	for (auto it = rentedVideoList.begin(); it != rentedVideoList.end(); ++it) {
		if (*it == title) {
			rentedVideoList.erase(it);
			break;
		}
		it++;
	}
}

int customerType::getNoOfRentals()
{
	return rentedVideoList.size();
}

int customerType::getAcctNo()
{
	return custAcctNo;
}

void customerType::printRentedVideo()
{
	for (auto it = rentedVideoList.begin(); it != rentedVideoList.end(); ++it) {
		cout << *it << ", ";
		it++;
	}
	cout << endl;
}

customerType::customerType(string first, string last, int acctNo) :personType2(first, last)
{
	custAcctNo = acctNo;
}

customerType::customerType()
{
	custAcctNo = 0;
}

bool customerType::operator==(customerType other)
{
	return (custAcctNo == other.custAcctNo);
}

bool customerType::operator!=(customerType other)
{
	return (custAcctNo != other.custAcctNo);
}

bool customerType::operator==(int id)
{
	return (custAcctNo == id);
}

ostream& operator << (ostream& os, customerType& cust)
{

	os << cust.custAcctNo << " "
		<< cust.getFirstName()
		<< " " << cust.getLastName()
		<< " " << cust.rentedVideoList.size() << endl;

	return os;
}

void customerType::insert(string item)
{
	rentedVideoList.push_front(item);
}