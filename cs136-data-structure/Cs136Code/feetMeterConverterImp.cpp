#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

const double  cmPerInch = 2.54;
const int inchPerFoot = 12;

void inputHelper() {
	cin.clear(); // clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
	cout << "Try again.\n";
	cout << "Your Number: ";
}

void getInput(int& value) {
	bool isValid = false;
	string userInput;

	while (!isValid) {
		try {
			cin >> userInput;
			if (userInput.empty())
				throw invalid_argument("Input is required.");

			if (userInput[0] == '-')
				throw out_of_range("Expected positive interger.");

			isValid = all_of(userInput.begin(), userInput.end(), 
				[](unsigned char c) { return isdigit(c); });

			if (!isValid)
				throw invalid_argument("Expected type interger.");

			value = stoi(userInput);
		}
		catch (const invalid_argument& e) {
			cerr << "invalid_argument: " << e.what() << endl;
			inputHelper();
		}
		catch (const out_of_range& e) {
			cerr << "out_of_range: " << e.what() << endl;
			inputHelper();
		}
	}
}

double normalizerHelper(const int& ft) {
	return (ft * inchPerFoot);
}

void getCentimeters(const int& ft, const int& in) {
	double toInches = (normalizerHelper(ft) + in) * cmPerInch;
	cout << ft << " ft ," << in << " inches = " << toInches  << " centimeters.";
}


void Test14_1() {

	int feet = 0;
	int inch = 0;

	cout << "Enter Feet:" << endl;
	cout << "Your Number: ";
	getInput(feet);

	cout << "Enter Inch:" << endl;
	cout << "Your Number: ";
	getInput(inch);
	getCentimeters(feet, inch);

}