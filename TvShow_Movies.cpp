
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// there are Class to define the properties of TV movies
class TVShowMovie {
protected:
    string MovieID;
    string MovieName;
    string MovieGenre;
    string ActorFirst;
    string ActorLast;
    string Language1;
    string Language2;
    int MovieDuration; // in minutes
    int Year;

public:
    // Constructor for the tv show movie 
    TVShowMovie(string ID, string Name, string Genre, string First, string Last, string Lang1, string Lang2, int Duration, int Y)
        : MovieID(ID), MovieName(Name), MovieGenre(Genre), ActorFirst(First), ActorLast(Last), Language1(Lang1), Language2(Lang2), MovieDuration(Duration), Year(Y) {}

    // there si a method to display movie information
    void displayInfo() const {
        cout << "Movie ID: " << MovieID << endl;
        cout << "Movie Name: " << MovieName << endl;
        cout << "Movie Genre: " << MovieGenre << endl;
        cout << "Actor: " << ActorFirst << " " << ActorLast << endl;
        cout << "Languages: " << Language1 << ", " << Language2 << endl;
        cout << "Duration: " << MovieDuration / 60 << " hours " << MovieDuration % 60 << " minutes " << endl;
        cout << "Year: " << Year << endl;
        cout << endl;
    }

    // here is get  for movieID
    string getMovieID() const {
        return MovieID;
    }
};

// here is class to represent the movie database
class MovieDatabase {
private:
    vector<TVShowMovie> movies;
    bool isPremium;

public:
    // Constructor
    MovieDatabase() : isPremium(false) {}

    // set  for the plan type (premium or basic)
    void setPlan(bool premium) {
        isPremium = premium;
    }

    // inserting  a movie into the database
    void insert(const string& ID, const string& Name, const string& Genre, const string& First, const string& Last, const string& Lang1, const string& Lang2, int Duration, int Y) {
        // here is yo check if the user has a basic plan and the genre is TV Show
        if (!isPremium && Genre != "TV Show") {
            cout << "Basic plan only supports movies. Skipping insertion of TV Show." << endl;
            return;
        }

        // Create a new TVShowMovie object and add it to the vector
        movies.push_back(TVShowMovie(ID, Name, Genre, First, Last, Lang1, Lang2, Duration, Y));
    }

    // Method to search for a movie by ID
    TVShowMovie* search(const string& movieID) {
        for (auto& movie : movies) {
            if (movie.getMovieID() == movieID) {
                return &movie;
            }
        }
        return nullptr; // Return nullptr if movie is not found
    }

    // Remove a movie by ID
    void remove(const string& movieID) {
        movies.erase(remove_if(movies.begin(), movies.end(), [&](const TVShowMovie& movie) { return movie.getMovieID() == movieID; }), movies.end());
    }

    // Display all movies
    void displayMovies() {
        cout << "Displaying movies here " << endl;
        for (const auto& movie : movies) {
            movie.displayInfo();
        }
    }
};

int main() {
    MovieDatabase Movies;

    // Set the plan type (true for premium, false for basic)
    bool isPremiumPlan = true; // Change this based on user input
    Movies.setPlan(isPremiumPlan);

    // Add movies to the vector
    Movies.insert("0000", "Dune", "Action", "Timothee", "Chalamet", "English", "Spanish", 166, 2024);
    Movies.insert("0001", "Spaceman", "Science Fiction", "Adam", "Sandler", "English", "Spanish", 108, 2024);
    Movies.insert("0002", "PoorThings", "TV Show", "Emma", "Stone", "English", "Spanish", 141, 2024); // TV Show
    Movies.insert("0003", "Inception", "Adventure", "Leonardo", "Dicaprio", "English", "Spanish", 148, 2010);
    Movies.insert("0004", "Interstellar", "Science Fiction", "Jonathan", "Nolan", "English", "Spanish", 169, 2014);

    // Attempt to insert a movie with existing ID (should fail)
    Movies.insert("0001", "Duplicate Movie", "Action", "Adam", "Ramones", "English", "Spanish", 120, 2023);

    // Displaying  movies
    Movies.displayMovies();

    return 0;
}

