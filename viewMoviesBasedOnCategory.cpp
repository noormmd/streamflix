#include "Movies.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//TRY ADDING GETTERS
// Function to display movies from CSV file
void displayMoviesFromCSV(const string& filename) {
    // Call the function to read movies from the CSV file
    vector<Movie> movies = readMoviesFromCSV(filename);

    // Display the movies
    for (const auto& movie : movies) {
        cout << "Name: " << movie.getName() << endl;
        cout << "Genre: " << movie.getGenre() << endl;
        cout << "Language: " << movie.getLanguage() << endl;
        cout << "Actor: " << movie.getActorFirst() << " " << movie.getActorLast() << endl;
        cout << "Duration: " << movie.getDuration() << " minutes" << endl;
        cout << "Release Year: " << movie.getYear() << endl << endl;
    }
}

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
            vector<string> fields = parseCSVLine(line);
            if (fields.size() == 8) {
                int movieID = stoi(fields[0]);
                string movieName = fields[1];
                string movieGenre = fields[2];
                string actorFirst = fields[3];
                string actorLast = fields[4];
                string durationString = fields[5];
                int movieDuration = parseDurationToMinutes(durationString);
                int year = stoi(fields[7]);
                string language = fields[6];

                // Create a Movie object and add it to the vector
                Movie movie(movieDuration, movieID, movieName, movieGenre, actorFirst, actorLast, year, language);
                movies.push_back(movie);
            }
        }

        file.close();
        return movies;
    }

    // // Open the CSV file
    // ifstream file("Movies.csv");
    // if (!file.is_open()) {
    //     cerr << "Error opening file!" << endl;
    //     return 1;
    // }

    // string line;
    // // Read the header line
    // getline(file, line);

    // // Prompt the user for criteria
    // cout << "Enter the desired genre: ";
    // string desiredGenre;
    // getline(cin, desiredGenre);

    // cout << "Enter the desired language: ";
    // string desiredLanguage;
    // getline(cin, desiredLanguage);

    // cout << "Enter the first name of the actor: ";
    // string desiredActorFirst;
    // getline(cin, desiredActorFirst);


    // cout << "Enter the last name of the actor: ";
    // string desiredActorLast;
    // getline(cin, desiredActorLast);

    // // Vectors to store movies matching the criteria
    // vector<Movie> matchingMovies;

    // // Read and process each line of the file
    // while (getline(file, line)) {
    //     vector<string> fields = parseCSVLine(line);
    //     // Check if we have enough fields to create a movie
    //     if (fields.size() == 8) {
    //         // Extract fields from the vector
    //         int movieID = stoi(fields[0]);
    //         string movieName = fields[1];
    //         string movieGenre = fields[2];
    //         string actorFirst = fields[3];
    //         string actorLast = fields[4];
    //         // Parsing movie duration from string to integer
    //         string durationString = fields[5];
    //         durationString = durationString.substr(0, durationString.find("h"));
    //         int movieDuration = stoi(durationString);
    //         // Year can be parsed as it is
    //         int year = stoi(fields[7]);
    //         // Language
    //         string language = fields[6];

    //         // Check if the movie matches the user's criteria
    //         if (movieGenre == desiredGenre && language == desiredLanguage &&
    //             actorFirst == desiredActorFirst && actorLast == desiredActorLast) {
    //             // Create a Movie object with the extracted fields
    //             Movie movie(movieDuration, movieID, movieName, movieGenre, actorFirst, actorLast);
    //             // Add the movie to the vector of matching movies
    //             matchingMovies.push_back(movie);
    //         }
    //     }
    // }

    // // Close the file
    // file.close();

    //If no movie is found, print the error message
    if (matchingMovies.empty()) {
        cout << "No movie found matching the specified criteria." << endl;
    } else {
        // Display the matching movies to the user
        cout << "Chosen Movie: " << endl;
        for (const auto &movie : matchingMovies) {
            movie.printDetails();
        }
    }

    return 0;
}

