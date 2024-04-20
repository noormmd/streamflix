#ifndef TVSHOWS_H
#define TVSHOWS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


// Structure for TV show
struct TVShow {
    string name;
    string genres; 
    string language;
    int releaseYear;
    int season;


    // Constructor to initialise the TV show
    TVShow(string name, string genres, string language, int releaseYear, int season) :
        name(name), genres(genres), language(language), releaseYear(releaseYear), season(season) {}
};

// Function to read TV shows from CSV file
std::vector<TVShow> readShowsFromCSV(const std::string& filename);

class TVshows {
    private:
    int episodeDuration;
    int showID;
    string showName;
    string showGenre;
    string actorFirst;
    string actorLast;
    int seasonsCount;
    vector<int> episodesCount;
    vector<string> genre;

    public:
    // Constructor
    TVshows(int duration, int id, const string& name, const string& genre, const string& first, const string& last,
            int seasons, const vector<int>& episodes, const vector<string>& genreList)
        : episodeDuration(duration), showID(id), showName(name), showGenre(genre), actorFirst(first),
          actorLast(last), seasonsCount(seasons), episodesCount(episodes), genre(genreList) {}
    
    int getSeasonCount() const {
        return seasonsCount;
    }

    int getEpisodeCount() const{
        return episodesCount.size(); //We want to return the total number of episodes
    }

    //void selectEpisode(int seasonNumber, int episodeNumber) {}

    void selectSeason(int seasonNumber) {}

    void selectShow() {}

    void watchShowLater() {}
    
};

#endif