#pragma once
#include <iostream>
using namespace std;

class CalculatorType {

private:
	int firstTerm;
	int secondTerm;

public:
	// constructor
	CalculatorType(int fTerm = 0, int sTerm = 0);

	// methods
	void add() const;
	void subtract() const;
	void multiply() const;
	void divide() const;

};