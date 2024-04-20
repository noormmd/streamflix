#include "Movies.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to parse a CSV line into individual fields
vector<string> parseCSVLine(const string &line) {
    vector<string> fields;
    stringstream ss(line);
    string field;
    while (getline(ss, field, ',')) { 
        fields.push_back(field);
    }
    return fields;
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
    // Open the CSV file
    ifstream file("Movies.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    // Read the header line
    getline(file, line);

    // Prompt the user for criteria
    cout << "Enter the desired genre: ";
    string desiredGenre;
    getline(cin, desiredGenre);

    cout << "Enter the desired language: ";
    string desiredLanguage;
    getline(cin, desiredLanguage);

    cout << "Enter the first name of the actor: ";
    string desiredActorFirst;
    getline(cin, desiredActorFirst);


    cout << "Enter the last name of the actor: ";
    string desiredActorLast;
    getline(cin, desiredActorLast);

    // Vectors to store movies matching the criteria
    vector<Movie> matchingMovies;

    // Read and process each line of the file
    while (getline(file, line)) {
        vector<string> fields = parseCSVLine(line);
        // Check if we have enough fields to create a movie
        if (fields.size() == 8) {
            // Extract fields from the vector
            int movieID = stoi(fields[0]);
            string movieName = fields[1];
            string movieGenre = fields[2];
            string actorFirst = fields[3];
            string actorLast = fields[4];
            // Parsing movie duration from string to integer
            string durationString = fields[5];
            durationString = durationString.substr(0, durationString.find("h"));
            int movieDuration = stoi(durationString);
            // Year can be parsed as it is
            int year = stoi(fields[7]);
            // Language
            string language = fields[6];

            // Check if the movie matches the user's criteria
            if (movieGenre == desiredGenre && language == desiredLanguage &&
                actorFirst == desiredActorFirst && actorLast == desiredActorLast) {
                // Create a Movie object with the extracted fields
                Movie movie(movieDuration, movieID, movieName, movieGenre, actorFirst, actorLast);
                // Add the movie to the vector of matching movies
                matchingMovies.push_back(movie);
            }
        }
    }

    // Close the file
    file.close();

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

