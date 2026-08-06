#include <iostream> 
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>

#include "21.2videoLinkedListType.h"

using namespace std;

void videoListType::searchVideoList(string title, bool& found,
    list<videoType>::iterator& location)
{
    found = false;   //set found to false

    location = find(videoList.begin(), videoList.end(), title);

    if (location != videoList.end())
        found = true;

}//end searchVideoList


bool videoListType::isVideoAvailable(string title)
{
    bool found;
    list<videoType>::iterator location;

    searchVideoList(title, found, location);

    if (found)
        found = ((*location).getNoOfCopiesInStock() > 0);
    else
        found = false;

    return found;
}

void videoListType::videoCheckIn(string title)
{
    bool found = false;
    list<videoType>::iterator location;;

    searchVideoList(title, found, location);  //search the list

    if (found)
    {
        (*location).checkIn();
        cout << "Thanks for returing: " << title << endl;
    }
    else
        cout << "The movie selected is invalid!" << endl;
}

void videoListType::videoCheckOut(string title)
{
    bool found = false;
    list<videoType>::iterator location;

    searchVideoList(title, found, location);  //search the list

    if (found) {
        (*location).checkOut();
        cout << "Enjoy your movie: " << title << endl;
    }        
    else
        cout << "Video not in stock " << endl;
}

bool videoListType::videoCheckTitle(string title)
{
    bool found = false;

    list<videoType>::iterator location;

    searchVideoList(title, found, location); //search the list

    return found;
}

void videoListType::videoUpdateInStock(string title, int num)
{
    bool found = false;
    list<videoType>::iterator location;

    searchVideoList(title, found, location); //search the list

    if (found)
        (*location).updateInStock(num);
    else
        cout << "Video not in stock " << endl;
}

void videoListType::videoSetCopiesInStock(string title, int num)
{
    bool found = false;
    list<videoType>::iterator location;

    searchVideoList(title, found, location);

    if (found)
        (*location).setCopiesInStock(num);
    else
        cout << "Video not in stock " << endl;
}

bool videoListType::videoSearch(string title)
{
    bool found = false;
    list<videoType>::iterator location;

    location = find(videoList.begin(), videoList.end(), title);

    if (location != videoList.end())
        found = true;

    return found;
}

void videoListType::videoPrintTitle()
{
    list<videoType>::iterator location;

    location = videoList.begin();
    while (location != videoList.end())
    {
        (*location).printTitle();
        location++;
    }
}

void videoListType::insert(const videoType& item) {
    videoList.push_back(item);
}

void videoListType::print() const {
    for (auto it = videoList.begin(); it != videoList.end(); ++it) {
        it->printInfo();
    }
}

string inputHelper() {
    string input;
    cout << "Enter Title: ";
    getline(cin >> ws, input);
    return input;
}

void menuHelper(videoListType& videos) {

    int choice = 0;
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
            videos.videoCheckOut(title);
            break;

        case 3:
            title = inputHelper();
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

        case 9:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
};

void Test21_2()
{    
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    int setInStock;

    videoListType videos;

    ifstream infile("videoDat.txt");

    if (!infile)
    {
        cout << "Cannot open videoDat.txt." << endl;
        return;
    }

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

    menuHelper(videos);
}