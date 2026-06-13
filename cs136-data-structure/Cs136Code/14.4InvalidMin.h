#pragma once
#include <exception>
#include <string>


class InvalidMin : public std::exception {
private:
    std::string message;

public:
    InvalidMin() : message("Invalid minute value out of bounds.") {}

    InvalidMin(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
