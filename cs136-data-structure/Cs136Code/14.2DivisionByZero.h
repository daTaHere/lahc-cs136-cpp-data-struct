#pragma once
#include <exception>
#include <string>
using namespace std;

// Custom class derive from base class with message optiona
class DivisionByZero : public exception {
private:
    string message;

public:
    DivisionByZero() : message("Division by zero") {}

    DivisionByZero(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};