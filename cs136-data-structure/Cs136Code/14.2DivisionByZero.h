#pragma once
#include <exception>
using namespace std;

class divisionByZero : public exception {
public:
    const char* what() const noexcept override {
        return "Division by zero";
    }
};