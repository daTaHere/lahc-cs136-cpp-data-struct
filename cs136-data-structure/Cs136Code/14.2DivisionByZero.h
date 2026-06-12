#pragma once
#include <exception>
#include <string>
using namespace std;

// Custom class derive from base class with message optiona
class divisionByZero : public exception {
private:
    string message;

public:
    divisionByZero() : message("Division by zero") {}

    divisionByZero(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};