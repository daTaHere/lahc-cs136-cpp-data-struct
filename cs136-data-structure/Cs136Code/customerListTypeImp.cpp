#include <iostream> 
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>

#include "21.3customerListType.h"

using namespace std;

bool customerListType::custSearchId(int id)
{
	bool found;
	list<customerType>::iterator location;

	searchCust(id, found, location);

	return found;
}

void customerListType::custReturnVideo(int id, string title)
{
	bool found;
	list<customerType>::iterator location;

	searchCust(id, found, location);

	if (found)
		(*location).returnVideo(title);
}

void customerListType::custRentVideo(int id, string title)
{
	bool found;
	list<customerType>::iterator location;

	searchCust(id, found, location);

	if (found)
		(*location).rentVideo(title);
}

int customerListType::custGetNoOfRentals(int id)
{
	bool found;
	list<customerType>::iterator location;

	searchCust(id, found, location);

	return (*location).getNoOfRentals();
}

void customerListType::rentedVideosInfo()
{
	list<customerType>::iterator location;

	location = custList.begin();

	cout << "         ######## Rented Video Info ########"
		<< endl << endl;

	while (location != custList.end())
	{
		if ((*location).getNoOfRentals() > 0)
		{
			cout << "Customer ID: " << (*location).getAcctNo()
				<< endl;
			cout << "Number of Rentals: "
				<< (*location).getNoOfRentals()
				<< endl;
			cout << "Videos Rented: ";
			(*location).printRentedVideo();
			cout << "*****************" << endl << endl;
		}
		location++;
	}
}


void customerListType::searchCust(int id, bool& found, list<customerType>::iterator& location)
{
	found = false;   //set found to false

	location = find(custList.begin(), custList.end(), id);

	if (location != custList.end())
		found = true;
}

void customerListType::insert(const customerType& cust)
{
	custList.push_front(cust);
}

void customerListType::print()
{

	for (auto it = custList.begin(); it != custList.end(); ++it) {
		it->print();
	}
}

void menuHelper(customerListType& customerList) {

	int choice = 0;
	string title;

	while (choice != 9)
	{
		cout << "\nSelect one of the following\n";
		cout << "1: To see if a particalur person is a memeber\n";
		cout << "2: Print a list of customers\n";
		cout << "9: To exit\n";
		cout << "\nEnter choice: ";

		cin >> choice;
		switch (choice)
		{
		case 1:
			int id;
			cout << "Enter id: ";
			cin >> id;
			customerList.custSearchId(id) ?
				cout << id << " is a member\n" :
				cout << id << " Not a customer\n";
			break;

		case 2:
			customerList.print();
			break;

		case 9:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid choice. Try again." << endl;
		}
	}
};

void Test21_3() {
	ifstream infile("custDat.txt");
	if (!infile)
	{
		cout << "Cannot open videoDat.txt." << endl;
		return ;
	}
	customerListType customerList;
	string fName, lName;
	int id;

	while (infile >> fName >> lName >> id)
	{

		customerType temp;

		temp.setCustInfo(
			fName,
			lName,
			id
		);

		customerList.insert(temp);

		// Handle last space after id
		infile.ignore();

	}

	infile.close();
	menuHelper(customerList);
}