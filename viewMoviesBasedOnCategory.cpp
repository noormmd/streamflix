#include "Movies.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Forward declaration of functions
vector<Movie> readMoviesFromCSV(const string& filename);
void displayMoviesFromCSV(const string& filename);
void findAndDisplayMovie(const string& genre, const string& language, const string& actorFirst, const string& actorLast);

// Function to convert duration string (e.g., "2h 28mins") to minutes
int parseDurationToMinutes(const string &durationString) {
    int hours = 0, minutes = 0;
    stringstream ss(durationString);
    while (ss >> hours) {
        if (ss.peek() == 'h') {
            ss.ignore();
            break;
        }
        ss.ignore();
    }
    ss >> minutes;
    return hours * 60 + minutes;
}

int main() {
    // Call the function to display movies from CSV file
    displayMoviesFromCSV("Movies.csv");

    // Ask user for preferences
    string genre, language, actorFirst, actorLast;
    cout << "Enter your preferences to find a movie:" << endl;
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Language: ";
    getline(cin, language);
    cout << "Actor's First Name: ";
    getline(cin, actorFirst);
    cout << "Actor's Last Name: ";
    getline(cin, actorLast);

    // Call function to find and display matching movie
    findAndDisplayMovie(genre, language, actorFirst, actorLast);

    return 0;
}

// Function to display movies from CSV file
void displayMoviesFromCSV(const string& filename) {
    // Call the function to read movies from the CSV file
    vector<Movie> movies = readMoviesFromCSV(filename);

    // Display the movies
    for (const auto& movie : movies) {
        cout << "Movie Name: " << movie.getMovieName() << endl;
        cout << "Genre: " << movie.getMovieGenre() << endl;
        cout << "Language: " << movie.getMovieLanguage() << endl;
        cout << "Duration: " << movie.getMovieDuration() << " minutes" << endl << endl;
    }
}

// Function to read movies from CSV file
vector<Movie> readMoviesFromCSV(const string& filename) {
    vector<Movie> movies;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return movies;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() == 8) {
            int movieID = stoi(fields[0]);
            string movieName = fields[1];
            string movieGenre = fields[2];
            string actorFirst = fields[3];
            string actorLast = fields[4];
            string durationString = fields[5];
            int movieDuration = parseDurationToMinutes(durationString);
            string language = fields[6];
            string releaseYear = fields[7];

            // Create a Movie object and add it to the vector
            Movie movie(movieID, movieName, movieGenre, actorFirst, actorLast, movieDuration, language, releaseYear);
            movies.push_back(movie);
        }
    }

    file.close();
    return movies;
}

// Function to find and display movie based on user preferences
void findAndDisplayMovie(const string& genre, const string& language, const string& actorFirst, const string& actorLast) {
    ifstream file("Movies.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    string line;
    getline(file, line); // Skip header line
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() == 8) {
            if (fields[2] == genre && fields[6] == language && fields[3] == actorFirst && fields[4] == actorLast) {
                cout << "Movie Found:" << endl;
                cout << "Movie Name: " << fields[1] << endl;
                cout << "Genre: " << fields[2] << endl;
                cout << "Language: " << fields[6] << endl;
                cout << "Duration: " << parseDurationToMinutes(fields[5]) << " minutes" << endl;
                found = true;
                break;
            }
        }
    }

    file.close();

    if (!found) {
        cout << "No movie found with the specified preferences." << endl;
    }
}
