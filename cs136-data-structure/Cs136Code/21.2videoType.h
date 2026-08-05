#pragma once
#include <iostream>
#include <string>
 
using namespace std;

class videoType
{
	friend ostream& operator<<(ostream&, const videoType&);
     
public:
    void setVideoInfo(string title, string star1, 
					  string star2, string producer, 
					  string director, string productionCo, 
    int setInStock);
      //Function to set the details of a video. 
      //Member variables are set according to the parameters.
      //Postcondition: videoTitle = title; movieStar1 = star1;  
      //movieStar2 = star2; movieProducer = producer; 
      //movieDirector = director; movieProductionCo = productionCo; 
      //copiesInStock = setInStock;
    int getNoOfCopiesInStock() const;
      //Function to check the number of copies in stock. 
      //The value of the data member copiesInStock is returned.
    void checkIn();
      //This function checks in a video. 
      //Number of copies in stock is incremented by one.
    void checkOut();
      //This function rents a video. 
      //Number of copies in stock is decremented by one.
    void printTitle() const;
      //Function to print the title of a movie.
    void printInfo() const;
      //Function the print the details of a video.
      //The title of the movie, stars, director, and so on are
      //displayed on the screen.

    bool checkTitle(string title);
      //Function to check is title is same as the title of the video.
      //Returns the value true if title is same as the title of 
      //the video and false otherwise.
    void updateInStock(int num);
      //Function to increment the number of copies in stock by 
      //adding the value of the parameter num.
      //Postcondition: copiesInStock = copiesInStock  + num;
    void setCopiesInStock(int num);
      //Function to set the number of copies in stock.
      //Postcondition: copiesInStock = num;

    string getTitle();
      //Returns title of the video

    videoType(string title = "" , string star1 = "", 
			  string star2 = "", string producer = "", 
			  string director = "", string productionCo = "", 
      		  int setInStock = 0);
      //Constructor
      //Member variables are set according to the 
      //incoming parameters. If no values are specified 
      //default values are assigned.
      //Postcondition: videoTitle = title; movieStar1 = star1; 
      //         movieStar2 = star2; movieProducer = producer;
      //         movieDirector = director;
      //         movieProductionCo = productionCo;
      //         copiesInStock = setInStock;

    bool operator==(videoType);
    bool operator!=(videoType);

private:
    string videoTitle;	//variable to store the name 
  							//of the movie
    string movieStar1;	//variable to store the name 
 							//of the star
    string movieStar2;	//variable to store the name 
 							//of the star 
    string movieProducer; //variable to store the name 
  							 //of the producer 
    string movieDirector; //variable to store the name 
 							 //of the director 
    string movieProductionCo; //variable to store the name 
                                 //of the production company 
    int copiesInStock; 	//variable to store the number of 
 						//copies in stock
};
