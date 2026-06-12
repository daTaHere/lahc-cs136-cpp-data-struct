#pragma once
#include <iostream>
using namespace std;
class ComplexType {
private:
    double realPart;
    double imaginaryPart;



public:
    //Constructor
    ComplexType(double real = 0, double imag = 0);

    // Getters and Setters
    void setComplex(const double& real, const double& imag);
    void getComplex(double& real, double& imag) const;

    //Overload the operators
    ComplexType operator+ (const ComplexType& other) const;
    ComplexType operator* (const ComplexType& other) const;
    bool operator== (const ComplexType& other) const;
   
    //Friend Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream& out, const ComplexType&);
    friend istream& operator>>(istream& in, ComplexType&);

    // 13.7 methods  ===========================
    ComplexType operator- (const ComplexType& other) const;
    ComplexType operator/ (const ComplexType& other) const;
};