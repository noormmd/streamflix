//these include necessary standard library 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


// these class define the properties of tv movies 
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



//here are all member variables to default value 
public:
    TVShowMovie() : MovieID(""), MovieName(""), MovieGenre(""), ActorFirst(""), ActorLast(""), Language1(""), Language2(""), MovieDuration(0), Year(0) {}

    TVShowMovie(string ID, string Name, string Genre, string First, string Last, string Lang1, string Lang2, int Duration, int Y)
    : MovieID(ID), MovieName(Name), MovieGenre(Genre), ActorFirst(First), ActorLast(Last), Language1(Lang1), Language2(Lang2), MovieDuration(Duration), Year(Y) {}


//here display information about the movies
    void displayInfo() const {
        cout << "Movie ID: " << MovieID << endl;
        cout << "Movie Name: " << MovieName << endl;
        cout << "Movie Genre: " << MovieGenre << endl;
        cout << "Actor: " << ActorFirst << " "<< ActorLast << endl;
        cout << "Languages: " << Language1 << ", " << Language2 << endl;
        cout << "Duration: " << MovieDuration / 60 << " hours " << MovieDuration % 60 << " minutes " << endl;
        cout << "Year: " << Year << endl;
        cout << endl;
    }


//here will show the returns ID of the movies 
    string getMovieID() const {
        return MovieID;
    }
};



//indicate whether the user  has premiun  plan or not 
class MovieDatabase {
private:
    unordered_map<string, TVShowMovie> table;
    bool isPremium; // it is Indicating whether the user has a premium plan or not


//here is the variable to false indicating a basic plan  
public:
    MovieDatabase() : isPremium(false) {}

    // Setter for the plan type which it says true for premiun , false  for basic 
    void setPlan(bool premium) {
        isPremium = premium;
    }


//here inserts a movie into the database, it is checking if the ID already exists and if the user has a basic plan and the genre is TV show.
    void insert(const string& ID, const string& Name, const string& Genre, const string& First, const string& Last, const string& Lang1, const string& Lang2, int Duration, int Y) {
        // in this part is Checking if the movie ID already exists
        if (table.find(ID) != table.end()) {
            cout << "Error: Movie with ID " << ID << " already exists. Skipping insertion." << endl;
            return;
        }

        // here is if the user has a basic plan and the genre is TV Show
        if (!isPremium && Genre != "TV Show") {
            cout << "Basic plan only supports movies. Skipping insertion of TV Show." << endl;
            return;
        }

        TVShowMovie movie(ID, Name, Genre, First, Last, Lang1, Lang2, Duration, Y);
        table[ID] = movie;
    }

    TVShowMovie* search(const string& movieID) {
        if (table.find(movieID) != table.end())
            return &table[movieID];
        else
            return nullptr;
    }

    void remove(const string& movieID) {
        table.erase(movieID);
    }

    void displayMovies() {
        cout << "DISPLAY MOVIES HERE" << endl;
        for (const auto& pair : table) {
            pair.second.displayInfo();
        }
    }
};

int moviesHashtable() {
    MovieDatabase Movies;

    // here is set plan type based on user selection (will be true for premium, and false for basic)
    bool isPremiumPlan = true; // Change this based on user input

    // Set the plan type (preparing the plan type )
    Movies.setPlan(isPremiumPlan);

    // Add movies to the hash table
    Movies.insert("0000", "Dune", "Action", "Timothee", "Chalamet", "English", "Spanish", 166, 2024);
    Movies.insert("0001", "Spaceman", "Science Fiction", "Adam", "Sandler", "English", "Spanish", 108, 2024);
    Movies.insert("0002", "PoorThings", "TV Show", "Emma", "Stone", "English", "Spanish", 141, 2024); // TV Show
    Movies.insert("0003", "Inception", "Adventure", "Leonardo", "Dicaprio", "English", "Spanish", 148, 2010);
    Movies.insert("0004", "Interstellar", "Science Fiction", "Jonathan", "Nolan", "English", "Spanish", 169, 2014);

    // Attempt to insert a movie with existing ID (should fail)
    Movies.insert("0001", "Duplicate Movie", "Action", "Adam", "Ramones", "English", "Spanish", 120, 2023);

    // Display movies
    Movies.displayMovies();

    return 0;
}
