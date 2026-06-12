#pragma once
#include <iostream>
using namespace std;

class calculatorType {

private:
	int firstTerm;
	int secondTerm;

public:
	// constructor
	calculatorType(int fTerm = 0, int sTerm = 0);

	// methods
	void add() const;
	void subtract() const;
	void multiply() const;
	void divide() const;

};