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
}

#endif