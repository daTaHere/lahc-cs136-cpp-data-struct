#pragma once
#include <iostream>
using namespace std;

class ClockType {
private:
    int hr;
    int min;
    int sec;

public:
    // Constructor
    ClockType(int hours = 0, int minutes = 0, int seconds = 0);

    // Setters and getters
    void setTime(int hours, int minutes, int seconds);
    void getTime(int& hours, int& minutes, int& seconds) const;

    // overload operators
    ClockType operator++();
    bool operator==(const ClockType& otherClock) const;
    bool operator!=(const ClockType& otherClock) const;
    bool operator<=(const ClockType& otherClock) const;
    bool operator<(const ClockType& otherClock) const;
    bool operator>=(const ClockType& otherClock) const;
    bool operator>(const ClockType& otherClock) const;


    // friend functions
    friend ostream& operator<<(ostream&, const ClockType&);
    friend istream& operator>>(istream&, ClockType&);
};