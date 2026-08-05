#include <iostream> 
#include <string>
#include <list>
#include "21.2videoType.h"

using namespace std;

class videoListType
{
public:
    bool videoSearch(string title);
    //This function searches the list to see if a particular
    //title, specified by the parameter title, is in store.
    //Returns true if the title is found, false otherwise.

    bool isVideoAvailable(string title);
    //This function returns true if at least one copy of a 
    //particular video is in store.

    void videoCheckIn(string title);
    //This function checks in a video returned by a customer.
    //Postcondition: copiesInstock is incremented by one.

    void videoCheckOut(string title);
    //This function checkes out a vedio, that is, 
    //rents a video.
    //Postcondition: copiesInStock is decremented by one.
    bool videoCheckTitle(string title);
    //This function returns true if there is a particular 
    //video in store.

    void videoUpdateInStock(string title, int num);
    //This function updates the number of copies of a video
    //by adding the value of the parameter num. The 
    //parameter title specifies the name of the video 
    //for the number of copies is to be updated.
    //Postcondition: copiesInStock = copiesInStock + num;

    void videoSetCopiesInStock(string title, int num);
    //This function reserts the number of copies of a video.
    //The parameter title specifies the name of the video
    //for the number of copies is to be reseted and the 
    //parameter num specifies the number of copies.
    //Postcondition: copiesInStock = num;

    void videoPrintTitle();
    //This function prints the titles of all videos in 
    //the store

    void print() const;

    void insert(const videoType&);

private:
    void searchVideoList(string title, bool& found,
        list<videoType>::iterator& location);
    //This function searches the video list for a 
    //particular video, specified by the parameter title. 
    //If the video is found, the parameter found is set to 
    //true; it is set to fasle otherwise. The parameter current 
    //points to the node containing the video.

    list<videoType> videoList;
};
