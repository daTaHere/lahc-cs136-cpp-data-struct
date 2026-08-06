#include <iostream>
#include <fstream>

#include "21.2videoLinkedListType.h"
#include "21.3customerListType.h"

using namespace std;

string inputHelper() {
    string input;
    cout << "Enter Title: ";
    getline(cin >> ws, input);
    return input;
}

void menuHelper(customerListType& cust, videoListType& videos) {

    int choice = 0;
    int custId = 0;
    string title;

    while (choice != 9)
    {
        cout << "\nSelect one of the following\n";
        cout << "1: To check if a particular video is in Store\n";
        cout << "2: To check out a video\n";
        cout << "3: To check in a video\n";
        cout << "4: To see if a particular video is in stock\n";
        cout << "5: To print Titles of all videos\n";
        cout << "6: To print a list of all videos\n";
        cout << "7: Print the list of customers\n";
        cout << "8: To print a list of which customers rented which videos\n";
        cout << "9: To exit\n";
        cout << "\nEnter choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            title = inputHelper();
            if (videos.videoSearch(title))
                cout << title << " was found in store.\n";
            else
                cout << title << " was not found in store.";

            break;

        case 2:
            title = inputHelper();
            cout << "Enter id: ";
            cin >> custId;
            cust.custRentVideo(custId, title);
            videos.videoCheckOut(title);

            break;

        case 3:
            title = inputHelper();
            cout << "Enter id: ";
            cin >> custId;
            cust.custReturnVideo(custId, title);
            videos.videoCheckIn(title);
            break;

        case 4:
            title = inputHelper();

            if (videos.isVideoAvailable(title))
                cout << "Currently in stock." << endl;
            else
                cout << "Video not in store" << endl;

            break;

        case 5:
            videos.videoPrintTitle();
            break;

        case 6:
            videos.print();
            break;
        case 7:
            cust.print();
            break;
        case 8:
            cust.rentedVideosInfo();;
            break;

        case 9:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
};

videoListType createDvdList(ifstream& infile) {
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    int setInStock;

    videoListType videos;

    while (getline(infile, title))
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);

        infile >> setInStock;

        // Handle last space after inStock int
        infile.ignore();

        videoType temp;

        temp.setVideoInfo(
            title,
            star1,
            star2,
            producer,
            director,
            productionCo,
            setInStock
        );

        videos.insert(temp);
    }

    infile.close();
    return videos;
}


customerListType createCustomerList(ifstream& infile) {

    customerListType customerList;
    string fName, lName;
    int id;

    while (infile >> fName >> lName >> id)
    {

        customerType temp;

        temp.setCustInfo(
            fName,
            lName,
            id
        );

        customerList.insert(temp);

        // Handle last space after id
        infile.ignore();

    }

    infile.close();
    return customerList;
}
void Test21_4() {
    // Write your main here

    ifstream infile("videoDat.txt");

    if (!infile)
    {
        cout << "Cannot open videoDat.txt." << endl;
     
    }


    videoListType dvdList = createDvdList(infile);

    infile.open("custDat.txt");
    customerListType customerList = createCustomerList(infile);
    menuHelper(customerList, dvdList);
}
