#pragma once
#include <iostream>
#include <string>
#include <list> 
#include "21.3customer.h"

using namespace std;

class customerListType
{
public:
	bool custSearchId(int id);
	void custReturnVideo(int id, string title);
	void custRentVideo(int id, string title);
	int  custGetNoOfRentals(int id);

	void rentedVideosInfo();

	void insert(const customerType&);

	void print();

private:
	void searchCust(int id, bool& found,
		list<customerType>::iterator& location);

	list<customerType> custList;
};