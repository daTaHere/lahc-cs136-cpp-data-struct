#pragma once
#include <iostream>
using namespace std;
class complexType {
private:
    double realPart;
    double imaginaryPart;



public:
    //Constructor
    complexType(double real = 0, double imag = 0);

    // Getters and Setters
    void setComplex(const double& real, const double& imag);
    void getComplex(double& real, double& imag) const;

    //Overload the operators
    complexType operator+ (const complexType& other) const;
    complexType operator* (const complexType& other) const;
    bool operator== (const complexType& other) const;
   
    //Friend Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream& out, const complexType&);
    friend istream& operator>>(istream& in, complexType&);

    // 13.7 methods  ===========================
    complexType operator- (const complexType& other) const;
    complexType operator/ (const complexType& other) const;
};