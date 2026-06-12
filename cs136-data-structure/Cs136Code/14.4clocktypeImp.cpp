#include <iostream>
#include "14.4ClockType.h"
#include "14.4InvalidHr.h"
#include "14.4InvalidMin.h"
#include "14.4InvalidSec.h"


using namespace std;

ClockType::ClockType(int hours, int minutes, int seconds) {
    setTime(hours, minutes, seconds);
}

void ClockType :: setTime(const int hours, const  int minutes, const  int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

void ClockType :: getTime(int& hours, int& minutes, int& seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

ClockType ClockType :: operator++() {
    sec++;
    if (sec > 59) {
        sec = 0;
        min++;
    }
   
    if (min > 59) {
        min = 0;
        hr++;
    }

    if (hr > 23)
        hr = 0;

    return *this;
}

bool ClockType :: operator==(const ClockType& otherClock) const {
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

bool ClockType :: operator<=(const ClockType& otherClock) const {
    return ((hr < otherClock.hr) || (hr == otherClock.hr && min < otherClock.min) 
        || (hr == otherClock.hr && min == otherClock.min &&sec <= otherClock.sec));
}

bool ClockType :: operator!=(const ClockType& otherClock) const {
    return (hr != otherClock.hr || min != otherClock.min || sec != otherClock.sec);
}

bool ClockType :: operator<(const ClockType& otherClock) const {
    return ((hr < otherClock.hr) ||  (hr == otherClock.hr && min < otherClock.min) 
        || (hr == otherClock.hr && min == otherClock.min && sec < otherClock.sec));
}

bool ClockType::operator>=(const ClockType& otherClock) const {
    return ((hr > otherClock.hr) || (hr == otherClock.hr && min > otherClock.min) 
        || (hr == otherClock.hr && min == otherClock.min && sec >= otherClock.sec));
}

bool ClockType::operator>(const ClockType& otherClock) const {
    return ((hr > otherClock.hr) || (hr == otherClock.hr && min > otherClock.min) 
        || (hr == otherClock.hr && min == otherClock.min && sec > otherClock.sec));
}

ostream& operator<<(ostream& cout, const ClockType& timeOut) {
    if (timeOut.hr < 10)
        cout << '0';
    cout << timeOut.hr << ':';
    if (timeOut.min < 10) 
        cout << '0';
    cout << timeOut.min << ':';
    if (timeOut.sec < 10)
        cout << '0';
    cout << timeOut.sec;
    return cout;
}

istream& operator>> (istream& in, ClockType& timeIn) {
    char ch;
    in >> timeIn.hr;
    if (timeIn.hr < 0 || timeIn.hr >= 24)
        timeIn.hr = 0;
    cin.get(ch);

    cin >> timeIn.min;
    if (timeIn.min < 0 || timeIn.min >= 60)
        timeIn.min = 0;
    in.get(ch);

    in >> timeIn.sec;
    if (timeIn.sec < 0 || timeIn.sec >= 60)
        timeIn.sec = 0;
    return in;
   
}

void Test14_4() {
    ClockType myClock;
    
    cout << "Enter the time in the form " << "hr:min:sec ";
    cin >> myClock;
    cout << endl;
    cout << "Line 13: The new time of myClock = " << myClock << endl;
    ++myClock;
    cout << "Line 15: After incrementing the time, " << "myClock = " << myClock << endl;
}