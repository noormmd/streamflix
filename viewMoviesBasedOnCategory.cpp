#include "Movies.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Forward declaration of functions
vector<Movie> readMoviesFromCSV(const string& filename);
void displayMoviesFromCSV(const vector<Movie>& movies);
void displayMatchingMovies(const vector<Movie>& movies, const string& desiredGenre, const string& desiredLanguage, const string& desiredActorFirst, const string& desiredActorLast);
void sortMoviesByReleaseYear(vector<Movie>& movies);

// Function to convert duration string (e.g., "2h 28min") to minutes
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

// Function to trim leading and trailing whitespace from a string
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n");
    size_t end = str.find_last_not_of(" \t\n");
    if (start == std::string::npos || end == std::string::npos) {
        return ""; // No non-whitespace characters found
    }
    return str.substr(start, end - start + 1);
}

int main() {
    // Call the function to read movies from CSV file
    vector<Movie> movies = readMoviesFromCSV("Movies.csv");

    // Sort movies by release year
    sortMoviesByReleaseYear(movies);

    // Display movies from CSV file
    displayMoviesFromCSV(movies);

    // Prompt the user for input
    cout << "Enter the desired genre: ";
    string desiredGenre;
    getline(cin, desiredGenre);

    cout << "Enter the desired language: ";
    string desiredLanguage;
    getline(cin, desiredLanguage);

    cout << "Enter the first name of the actor: ";
    string desiredActorFirst;
    getline(cin, desiredActorFirst);
    desiredActorFirst = trim(desiredActorFirst);

    cout << "Enter the last name of the actor: ";
    string desiredActorLast;
    getline(cin, desiredActorLast);
    desiredActorLast = trim(desiredActorLast);

    // Display matching movies
    displayMatchingMovies(movies, desiredGenre, desiredLanguage, desiredActorFirst, desiredActorLast);

    return 0;
}

// Function to display movies from CSV file
void displayMoviesFromCSV(const vector<Movie>& movies) {
    cout << "Movies from CSV file:" << endl;
    for (const auto& movie : movies) {
        movie.printDetails();
        cout << endl;
    }
}

// Function to display movies matching the user's criteria
void displayMatchingMovies(const vector<Movie>& movies, const string& desiredGenre, const string& desiredLanguage, const string& desiredActorFirst, const string& desiredActorLast) {
    cout << "Desired Genre: " << desiredGenre << endl;
    cout << "Desired Language: " << desiredLanguage << endl;
    cout << "Desired Actor First Name: " << desiredActorFirst << endl;
    cout << "Desired Actor Last Name: " << desiredActorLast << endl;
    
    vector<Movie> matchingMovies;

    for (const auto& movie : movies) {
        cout << "Checking movie: " << movie.getMovieName() << endl;
        cout << "Movie Genre: " << movie.getMovieGenre() << ", Language: " << movie.getMovieLanguage() << ", Actor First Name: " << movie.getActorFirst() << ", Actor Last Name: " << movie.getActorLast() << endl;
        
        if (movie.getMovieGenre() == desiredGenre &&
            movie.getMovieLanguage() == desiredLanguage &&
            movie.getActorFirst() == desiredActorFirst &&
            movie.getActorLast() == desiredActorLast) {
            matchingMovies.push_back(movie);
        }
    }

    if (matchingMovies.empty()) {
        cout << "No movie found matching the specified criteria." << endl;
    } else {
        cout << "Matching Movies: " << endl;
        for (const auto& movie : matchingMovies) {
            movie.printDetails();
            cout << endl;
        }
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
            Movie movie(movieDuration, movieID, movieName, movieGenre, actorFirst, actorLast);
            movie.setReleaseYear(releaseyear);
            movie.setLanguage(language);
            movies.push_back(movie);
        }
    }

    file.close();
    return movies;
}

// Function to sort movies by release year using bubble sort
void sortMoviesByReleaseYear(vector<Movie>& movies) {
    int n = movies.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare release years and swap if needed
            if (movies[j].getReleaseYear() > movies[j + 1].getReleaseYear()) {
                swap(movies[j], movies[j + 1]);
            }
        }
    }
}
