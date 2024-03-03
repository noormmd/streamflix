#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Movie {
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
};

class User {
private:
    string username;
    string email;
    string password;
    string selectedPlan;
public:
    User(string username, string email, string password)
        : username(username), email(email), password(password){}

    string getUsername() const {
        return username;
    }

    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    void setSelectedPlan(string plan) {
        selectedPlan = plan;
    }

    void registerUser() {
        //function to register user
    }

    void login() {
        //function to log user in streamflix
    }

    void choosePlan(string plan) {
        selectedPlan = plan;
    }
};

class TVShow {
private:
    int seasonCount;
    vector<int> episodeCount;

public:
    TVShow(int seasonCount, const vector<int>& episodeCount)
        : seasonCount(seasonCount), episodeCount(episodeCount) {}
    
    int getSeasonCount() const {
        return seasonCount;
    }

    int getEpisodeCount(int seasonNumber) const {
        if (seasonNumber >= 1 && seasonNumber <= seasonCount){
            return episodeCount[seasonNumber - 1];
        } else {
            return -1; //Error handling
        }
    }

    void selectEpisode(int seasonNumber, int episodeNumber) {
        if (seasonNumber >= 1 && seasonNumber <= seasonCount && episodeNumber >= 1 && episodeNumber <= episodeCount[seasonNumber - 1]) {
            cout << "Selected Season " << seasonNumber << ", Episode " << episodeNumber << endl;
        } else {
            cout << "Invalid season or episode number." << endl;
        }
    }

    void selectSeason(int seasonNumber) {
        if (seasonNumber >= 1 && seasonNumber <= seasonCount) {
            cout << "Selected Season " << seasonNumber << endl;
        } else {
            cout << "Invalid season number." << endl;
        }
    }

    void selectShow() {
        cout << "Selected the TV show." << endl;
    }

    void watchShowLater(){
        cout << "Added the TV show to watch later list." << endl;
    }
};

class Plan {
private:
    float price;
    vector<string> planOptions;
    bool available;

public:
    Plan(float price, const vector<string>& planOptions, bool available)
        : price(price), planOptions(planOptions), available(available) {}

    void displayPlan(string planName){
        cout << "Plan: " << planName << endl;
        cout << "Price: £" << price << endl;
        cout << "Options: ";
        for (const auto& option : planOptions){
            cout << option << " ";
        }
        cout << endl;
        cout << "Availability: " << (available ? "Available" : "Discontinued") << endl;
    }

    float totalPrice(int subscriptionDuration) {
        return price * subscriptionDuration;
    }

    bool isAvailable(){
        return available;
    }
};
#endif
