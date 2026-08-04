#pragma once

#include <string> 

using namespace std;

class personType
{
    friend istream& operator>>(istream&, personType&);
    friend ostream& operator<<(ostream&, const personType&);

public:
    void setName(string first, string last);
    //Function to set firstName and lastName according 
    //to the parameters.
    //Postcondition: firstName = first; lastName = last

    string getFirstName() const;
    //Function to return the first name.
    //Postcondition: The value of firstName is returned.

    string getLastName() const;
    //Function to return the last name.
    //Postcondition: The value of lastName is returned.

    personType(string first = "", string last = "");
    //Constructor
    //Sets firstName and lastName according to the 
    //parameters. The default values of the parameters are 
    //empty strings.
    //Postcondition: firstName = first; lastName = last  

      //overload the relational operators
    bool operator==(const personType& right) const;
    bool operator!=(const personType& right) const;
    bool operator<=(const personType& right) const;
    bool operator<(const personType& right) const;
    bool operator>=(const personType& right) const;
    bool operator>(const personType& right) const;

protected:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
};