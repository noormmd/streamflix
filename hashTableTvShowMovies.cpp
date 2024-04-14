#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

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
    TVShowMovie() : MovieID(""), MovieName(""), MovieGenre(""), ActorFirst(""), ActorLast(""), Language1(""), Language2(""), MovieDuration(0), Year(0) {}

    TVShowMovie(string ID, string Name, string Genre, string First, string Last, string Lang1, string Lang2, int Duration, int Y)
    : MovieID(ID), MovieName(Name), MovieGenre(Genre), ActorFirst(First), ActorLast(Last), Language1(Lang1), Language2(Lang2), MovieDuration(Duration), Year(Y) {}

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

    string getMovieID() const {
        return MovieID;
    }
};


class MovieDatabase {
private:
    unordered_map<string, TVShowMovie> table;

public:
    void insert(const string& ID, const string& Name, const string& Genre, const string& First, const string& Last, const string& Lang1, const string& Lang2, int Duration, int Y) {
        // Check if the movie ID already exists
        if (table.find(ID) != table.end()) {
            cout << "Error: Movie with ID " << ID << " already exists. Skipping insertion." << endl;
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
};

int main() {
    MovieDatabase Movies;

    // Add movies to the hash table
    Movies.insert("0000", "Dune", "Action", "Timothee", "Chalamet", "English", "Spanish", 166, 2024);
    Movies.insert("0001", "Spaceman", "Science Fiction", "Adam", "Sandler", "English", "Spanish", 108, 2024);
    Movies.insert("0002", "PoorThings", "Science Fiction", "Emma", "Stone", "English", "Spanish", 141, 2024);
    Movies.insert("0003", "Inception", "Adventure", "Leonardo", "Dicaprio", "English", "Spanish", 148, 2010);
    Movies.insert("0004", "Interstellar", "Science Fiction", "Jonathan", "Nolan", "English", "Spanish", 169, 2014);

    // Attempt to insert a movie with existing ID (should fail)
    Movies.insert("0001", "Duplicate Movie", "Action", "Adam", "Ramones", "English", "Spanish", 120, 2023);

    // Display information about movies
    cout << "Movies Information:" << endl;
    for (const auto& movieID : {"0001", "0002", "0003", "0004", "0005"}) {
        TVShowMovie* movie = Movies.search(movieID);
        if (movie != nullptr) {
            movie->displayInfo();
        }
    }

    return 0;
}


