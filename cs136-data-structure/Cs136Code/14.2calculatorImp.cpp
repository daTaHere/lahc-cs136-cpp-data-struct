#include <iostream>
#include <iomanip> 
#include "14.2CalculatorType.h"
#include "14.2DivisionByZero.h"
using namespace std;

// Prototypes
int getInput(bool rejectZero);
void calculatorInputHelper(const string message);

CalculatorType :: CalculatorType(int fTerm, int sTerm) 
    : firstTerm(fTerm), secondTerm(sTerm) {};

void CalculatorType :: add() const  {
    cout << firstTerm << " + " << secondTerm << " = " << firstTerm + secondTerm << endl;
}

void CalculatorType::subtract() const  {
    cout << firstTerm << " - " << secondTerm << " = " << firstTerm - secondTerm << endl;
}

void CalculatorType::multiply() const {
    cout << firstTerm << " * " << secondTerm << " = " << firstTerm * secondTerm << endl;
}

void CalculatorType :: divide() const {
    double result = firstTerm / static_cast<double>(secondTerm);
    cout << fixed << showpoint << setprecision(2);
    cout << firstTerm << " / " << secondTerm << " = " << result << endl;
}

char getOperation(bool& isDivision) {

    char userInput;

    while (true) {
        try {
            cin >> userInput;
            if (!cin)
                throw invalid_argument("Input error.");
            if ( userInput != '+' && userInput != '-' && userInput != '*' && userInput != '/'  )
                throw invalid_argument("Invalid input Expected Arithemic Operator.");
            isDivision = (userInput == '/') ? true : false;
            return userInput;
        }
        catch (const invalid_argument& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            calculatorInputHelper("Your Operation: ");
        }
        catch (const out_of_range& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            calculatorInputHelper("Your Operation: ");
        }
    }
}

int getInput(bool rejectZero = false) {
    string userInput;

    while (true) {
        try {
            cin >> userInput;

            if (userInput.empty())
                throw invalid_argument("Input is required.");

            // Track input cast length
            size_t pos;
            int value = stoi(userInput, &pos);

            // Truncated input string guard
            if (pos != userInput.length())
                throw invalid_argument("Expected integer input.");

            if (rejectZero && value == 0)
                throw DivisionByZero("Expect non zero value");  // custom exception handler

            return value;
        }
        catch (const invalid_argument& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            calculatorInputHelper("Your Number: ");
        }
        catch (const DivisionByZero& e) {
            cerr << "DivisionByZero: " << e.what() << endl;
            calculatorInputHelper("Your Number: ");
        }
    }
}

void calculatorInputHelper(const string message) {
    cin.clear(); // clear error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    cout << "Try again.\n";
    cout << message;
}

void Test14_2() {
    char operation;
    int x, y;
    bool isDivision = false;
    bool stillCalculating = false;
    cout << "Enter first term: ";
    x = getInput();
    cout << "Enter operation: ";
    operation = getOperation(isDivision);
    cout << (isDivision ? "Input must be Non-Zero\nEnter second term : " : "Enter second term: ");
    y = getInput(isDivision);

    CalculatorType calculate(x, y);

        switch (operation) {
        case '+':
            calculate.add();
            break;
        case '-':
            calculate.subtract();
            break;
        case '*':
            calculate.multiply();
            break;
        case '/':
            calculate.divide();
            break;
        }
}
