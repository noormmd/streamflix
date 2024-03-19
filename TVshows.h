#ifndef TVSHOWS_H
#define TVSHOWS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class TVshows {
    private:
    int episodeDuration;
    int showID;
    string showName;
    string showGenre;
    string actorFirst;
    string actorLast;
    vector<int> seasonsCount;
    vector<int> episodesCount;
    vector<string> genre;

    public:
    // Constructor
    TVshows(int duration, int id, const string& name, const string& genre, const string& first, const string& last,
            int seasons, const vector<int>& episodes, const vector<string>& genreList)
        : episodeDuration(duration), showID(id), showName(name), showGenre(genre), actorFirst(first),
          actorLast(last), seasonsCount(seasons), episodeCount(episodes), genre(genreList) {}
    
    int getSeasonCount() const {
        return seasonCount;
    }

    int getEpisodeCount() const{
        return episodeCount.size(); //We want to return the total number of episodes
    }

    void selectEpisode(int seasonNumber, int episodeNumber) {}

    void selectSeason(int seasonNumber) {}

    void selectShow() {}

    void watchShowLater() {}
    
};

#endif