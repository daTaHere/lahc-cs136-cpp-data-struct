#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);
bool isStringPalindrome(string str, int first, int last);

bool isPalindrome(string str) {
    return isStringPalindrome(str, 0, str.length() - 1);
}

bool isStringPalindrome(string str, int first, int last) {
    if ( (last - first) == 0 )
        return true;
    else if ( (last - first) == 1 )  {
        if (str[first] == str[last])
            return true;
        else
            return false;
    }
    else if (str[first] != str[last])
        return false;
    else {
        //return edit this line;
        return isStringPalindrome(str, first + 1, last - 1);
    }
}

void Test15_6() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);
    cout << endl;

    if (isPalindrome(str))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;
    system("pause");

}