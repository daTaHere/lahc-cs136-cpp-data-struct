#include <iostream>
#include <vector>
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

ostream& operator<<(ostream& out, const ClockType& timeOut) {
    if (timeOut.hr < 10)
        out << '0';
    out << timeOut.hr << ':';
    if (timeOut.min < 10) 
        out << '0';
    out << timeOut.min << ':';
    if (timeOut.sec < 10)
        out << '0';
    out << timeOut.sec;
    return out;
}

istream& operator>> (istream& in, ClockType& timeIn) {
    char ch;
    in >> timeIn.hr;
    if (timeIn.hr < 0 || timeIn.hr >= 24)
        timeIn.hr = 0;
    in.get(ch);

    in >> timeIn.min;
    if (timeIn.min < 0 || timeIn.min >= 60)
        timeIn.min = 0;
    in.get(ch);

    in >> timeIn.sec;
    if (timeIn.sec < 0 || timeIn.sec >= 60)
        timeIn.sec = 0;
    return in;
}



//====  14.4 ================================

void clockInputHelper(const string message) {
    cin.clear(); // clear error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    cout << "Try again.\n";
    cout << message;
}

vector<int>  isValidTime() {
    int hr, min, sec;
    vector<int> time;

    while (true) {
        try {
            char colon1, colon2;
            cin >> hr >> colon1 >> min >> colon2 >> sec;

            if (cin.fail() || colon1 != ':' || colon2 != ':')
                throw invalid_argument("Time formate invalid expect hr : min : sec");
            if (hr < 0 || hr > 12)
                throw InvalidHr();
            time.push_back(hr);
            if (min < 0 || min >= 60)
                throw InvalidMin();
            time.push_back(min);
            if (sec < 0 || sec >= 60)
                throw InvalidSec();
            time.push_back(sec);
            return time;

        }
        catch (invalid_argument& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            clockInputHelper("Input time: ");
        }
        catch (InvalidHr& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            clockInputHelper("Input time: ");
        }
        catch (InvalidMin& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            clockInputHelper("Input time: ");
        }
        catch (InvalidSec& e) {
            cerr << "invalid_argument: " << e.what() << endl;
            clockInputHelper("Input time: ");
        }
        catch (exception& e) {
            cerr << "Unknow exception: " << e.what() << endl;
        }
    }
}

void clockConvertor(const vector<int>& time) {
    char zone;
    bool isValid = false;
    
    int hr = time.at(0);
    int min = time.at(1);
    int sec = time.at(2);
    
    do {
        cout << "1: AM\n";
        cout << "2: PM\n";
        cout << "Enter 1 or 2: ";
        cin >> zone;
        switch(zone) {
        case '1':
            cout << (hr != 12 ? hr : 0) << ':' << min << ':' << sec << endl;
            isValid = true;
            break;
        case '2':
            cout << (hr == 12 ? hr : hr + 12) << ':' << min << ':' << sec << endl;
            isValid = true;
            break;
        default:
            continue;
        }
    } while (!isValid);

    

}


void Test14_4() {
    ClockType myClock;
    
    cout << "Enter the time in the form " << "hr:min:sec ";
    vector<int> time = isValidTime();
    clockConvertor(time);

    //cin >> myClock;
    //cout << endl;
    //cout << "Line 13: The new time of myClock = " << myClock << endl;
    //++myClock;
    //cout << "Line 15: After incrementing the time, " << "myClock = " << myClock << endl;
}