#pragma once

#include <iostream>
#include <list>
#include "21.3personType.h"
#include <string> 

using namespace std;

class customerType : public personType2
{
	friend ostream& operator<<(ostream&, customerType&);
	// overload stream insertion operator
public:
	void print();
	//Output account number, first name, last name, and 
	//number of rentals, in the form:
	//acctNo firstName lastName noOfRentals
	void setCustInfo(string first, string last, int acctNo);
	//Set firstName, lastName, and account number according 
	//to the parameters
	//firstName = first; lastName = last; 
	void rentVideo(string);
	//This function rents a video to the customer
	void returnVideo(string);
	//This function renturns a video to the customer

	int getNoOfRentals();
	//This function returns the number of
	//videos rented by the customer.
	int getAcctNo();
	//This function returns the account number of
	//the customer.
	void printRentedVideo();

	customerType(string first, string last, int acctNo);
	//constructor with parameters
	//set firstName and lastName according to the parameters
	//firstName = first; lastName = last;
	customerType();
	//Default constructor;
	//intialize firstName and lastName, and custAcctNo 
	//Postcondition: firstName = ""; lastName = "";
	//		          custAcctNo = 0;

	   //overload operators for comparisons 
	bool operator==(customerType);
	bool operator!=(customerType);

	bool operator==(int);

	void insert(const string);

private:
	int custAcctNo;    //store account number
	list<string> rentedVideoList;
};
