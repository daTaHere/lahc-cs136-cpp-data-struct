#pragma once
#include <exception>
#include <string>


class InvalidSec : public std::exception {
private:
    std::string message;

public:
    InvalidSec() : message("Invalid seconds value") {}

    InvalidSec(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
