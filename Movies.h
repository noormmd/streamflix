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
string releaseyear;
string language;

public:
    // Constructor
    Movie(int duration, int id, const string& name, const string& genre, const string& first, const string& last, const string& release, const string& lang)
        : movieDuration(duration), movieID(id), movieName(name), movieGenre(genre),
          actorFirst(first), actorLast(last), releaseYear(release), language(lang) {}

    string getMovieID() const
    {
        return to_string(movieID);
    };

    string getMovieName() const
    {
        return movieName;
    };

string getReleaseYear() const
    {
        return release;
    };

    string getMovieLanguage() const
    {
        return language;
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
    };

      string getMovieGenre() const {
        return movieGenre;
    };
    
    void printDetails() const {
        cout << "Movie ID: " << getMovieID() << endl
             << "Movie Name: " << getMovieName() << endl
             << "Genre: " << getMovieGenre() << endl
             << "Starring: " << getActorFirst() << " " << getActorLast() << endl
             << "Duration: " << getMovieDuration() << " minutes" << endl
             << "Release Year: " << getReleaseYear() << endl
             << "Language: " << getMovieLanguage() << endl;
    }
};
#endif