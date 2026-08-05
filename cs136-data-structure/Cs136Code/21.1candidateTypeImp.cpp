#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include "21.1candidateType.h"

using namespace std;

void candidateType::setVotes(int region, int votes)
{
    votesByRegion[region - 1] = votes;
}

void candidateType::updateVotesByRegion(int region, int votes)
{
    votesByRegion[region - 1] = votesByRegion[region - 1]
        + votes;
}

void candidateType::calculateTotalVotes()
{
    int i;

    totalVotes = 0;

    for (i = 0; i < NO_OF_REGIONS; i++)
        totalVotes += votesByRegion[i];
}

int candidateType::getTotalVotes() const
{
    return totalVotes;
}

void candidateType::printData() const
{
    cout << left
        << setw(8) << firstName << " "
        << setw(8) << lastName << " ";

    cout << right;
    for (int i = 0; i < NO_OF_REGIONS; i++)
        cout << setw(8) << votesByRegion[i] << " ";
    cout << setw(7) << totalVotes << endl;
}

candidateType::candidateType()
{
    for (int i = 0; i < NO_OF_REGIONS; i++)
        votesByRegion[i] = 0;

    totalVotes = 0;
}

bool candidateType::operator==(const candidateType& right) const
{
    return (firstName == right.firstName
        && lastName == right.lastName);
}

bool candidateType::operator!=(const candidateType& right) const
{
    return (firstName != right.firstName
        || lastName != right.lastName);
}

bool candidateType::operator<=(const candidateType& right) const
{
    return (lastName <= right.lastName ||
        (lastName == right.lastName &&
            firstName <= right.firstName));
}

bool candidateType::operator<(const candidateType& right) const
{
    return (lastName < right.lastName ||
        (lastName == right.lastName &&
            firstName < right.firstName));
}

bool candidateType::operator>=(const candidateType& right) const
{
    return (lastName >= right.lastName ||
        (lastName == right.lastName &&
            firstName >= right.firstName));
}

bool candidateType::operator>(const candidateType& right) const
{
    return (lastName > right.lastName ||
        (lastName == right.lastName &&
            firstName > right.firstName));
}

const candidateType& candidateType::operator=
(const candidateType& right)
{
    if (this != &right)  // avoid self-assignment
    {
        firstName = right.firstName;
        lastName = right.lastName;

        for (int i = 0; i < NO_OF_REGIONS; i++)
            votesByRegion[i] = right.votesByRegion[i];

        totalVotes = right.totalVotes;
    }

    return *this;
}

const candidateType& candidateType::operator=
(const personType& right)
{
    firstName = right.getFirstName();
    lastName = right.getLastName();

    return *this;
}

void Test21_1() {
    string fName;
    string lName;
    int region;
    int votes;

    int totalVotesPolled = 0;

    list<candidateType> candidateList;
    list<candidateType>::iterator winner;

    ifstream infile("candData.txt");

    if (!infile)
    {
        cout << "Cannot open candData.txt." << endl;
        return;
    }

    // Add candidates
    while (infile >> fName >> lName)
    {
        candidateType temp;

        temp.setName(fName, lName);
        candidateList.push_back(temp);
    }

    infile.close();

    infile.open("voteData.txt");

    if (!infile)
    {
        cout << "Cannot open voteData.txt." << endl;
        return;
    }

    // Process votes by region
    while (infile >> fName >> lName >> region >> votes)
    {

        for (auto it = candidateList.begin(); it != candidateList.end(); ++it)
        {
            if (it->getFirstName() == fName && it->getLastName() == lName)
            {
                it->updateVotesByRegion(region, votes);
                break;
            }
        }
    }

    infile.close();

    // Process total votes
    for (auto it = candidateList.begin(); it != candidateList.end(); ++it)
    {
        it->calculateTotalVotes();
        totalVotesPolled += it->getTotalVotes();
    }

    // Sort by last name
    candidateList.sort();

    // Find the winner.
    winner = candidateList.begin();

    for (auto it = candidateList.begin(); it != candidateList.end(); ++it)
    {
        if (it->getTotalVotes() > winner->getTotalVotes())
        {
            winner = it;
        }
    }


    cout << "Candidate Name    Region1  Region2  Region3  Region4   Total" << endl;

    for (auto it = candidateList.begin(); it != candidateList.end(); ++it)
    {
        it->printData();
    }


    cout << endl;

    cout << "Winner: "
        << winner->getFirstName() << " "
        << winner->getLastName()
        << ", Votes Received: "
        << winner->getTotalVotes()
        << endl;

    cout << endl;

    cout << "Total votes polled: "
        << totalVotesPolled
        << endl;
}