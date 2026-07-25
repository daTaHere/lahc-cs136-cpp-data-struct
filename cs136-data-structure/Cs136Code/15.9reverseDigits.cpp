#include <iostream>

using namespace std;

void reverseDigits(long num, long& revNum, long& multip) {
    if (num < 10)
        revNum = num;
    else {
        //reverseDigits();edit this line
        reverseDigits(num/10, revNum,multip);
        multip = 10 * multip;
        revNum = (num % 10) * multip + revNum;
    }
}

void Test15_9() {
    long number;
    long reverseNumber;
    long multiplier = 1;
    bool isNegative = false;

    cout << "Enter an integer: ";
    cin >> number;
    cout << endl;

    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    reverseDigits(number, reverseNumber, multiplier);

    if (isNegative)
        reverseNumber = -reverseNumber;

    cout << number << " after digits reversed = "
        << reverseNumber << endl;
    system("pause");
}
