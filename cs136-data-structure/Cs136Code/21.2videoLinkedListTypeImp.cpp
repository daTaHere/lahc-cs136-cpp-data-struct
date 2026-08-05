#include <iostream>
#include <fstream>
#include "21.2videoLinkedListType.h"

void videoListType::insert(const videoType& item) {
    videoList.push_back(item);
}

void videoListType::print() const {
    for (auto it = videoList.begin(); it != videoList.end(); ++it) {
        it->printInfo();
    }
}

void menuHelper(videoListType& videos) {

    int choice = 0;

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
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
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
}

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