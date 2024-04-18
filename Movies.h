#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Movie
{
private:
    int movieDuration;
    int movieID;
    string movieName;
    string movieGenre;
    string actorFirst;
    string actorLast;

public:
    Movie(int movieDuration, int MovieID, string movieName, string movieGenre, string actorFirst, string actorLast)
        : movieDuration(movieDuration), movieID(movieID), movieName(movieName), movieGenre(movieGenre),
          actorFirst(actorFirst), actorLast(actorLast) {}

    string getMovieID() const
    {
        return to_string(movieID);
    };

    string getMovieName() const
    {
        return movieName;
    };

    string getActorFirst() const
    {
        return actorFirst;
    };

    string getActorLast() const
    {

        return actorLast;
    };
    int getMovieDuration() const
    {
        return movieDuration;
    }
      string getMovieGenre() const {
        return movieGenre;
    }
    
    void printDetails() const {
        cout << "Movie ID: " << getMovieID() << endl
             << "Movie Name: " << getMovieName() << endl
             << "Genre: " << getMovieGenre() << endl
             << "Starring: " << getActorFirst() << " " << getActorLast() << endl
             << "Duration: " << getMovieDuration() << " minutes" << endl;
    }
};
#endif