#pragma once
#include <exception>
#include <string>


class InvalidHr : public std :: exception {
private:
    std :: string message;

public:
    InvalidHr() : message("Invalid hour value out of bounds") {}

    InvalidHr(const std :: string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
