#include "Movies.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Function to parse a CSV line into individual fields
vector<string> parseCSVLine(const string &line) {
    vector<string> fields;
    stringstream ss(line);
    string field;
    while (getline(ss, field, ',')) {
        fields.push_back(field);
    }
    return fields;
}

int main() {
    //Open the CSV file
    ifstream file("Movies.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    //Read the header line
    getline(file, line);

    //Read and process each line of the file
    while (getline(file, line)) {
        vector<string> fields = parseCSVLine(line);
        //Check if we have enough fields to create a movie
        if (fields.size() == 8) {
            //Extract fields from the vector
            int movieID = stoi(fields[0]);
            string movieName = fields[1];
            string movieGenre = fields[2];
            string actorFirst = fields[3];
            string actorLast = fields[4];
            //Parsing movie duration from string to integer
            string durationString = fields[5];
            durationString = durationString.substr(0, durationString.find("h"));
            int movieDuration = stoi(durationString);
            //Year can be parsed as it is
            int year = stoi(fields[7]);
            //Language
            string language = fields[6];

            //Check if the movie matches the criteria
            string desiredGenre = "Science Fiction"; 
            string desiredLanguage = "English"; 
            string desiredActorFirst = "Adam";
            string desiredActorLast = "Sandler"; 

            if (movieGenre == desiredGenre && language == desiredLanguage &&
                actorFirst == desiredActorFirst && actorLast == desiredActorLast) {
                //Create a Movie object with the extracted fields
                Movie movie(movieDuration, movieID, movieName, movieGenre, actorFirst, actorLast);
                // Print the movie details
                movie.printDetails();
                cout << "Year: " << year << endl;
                cout << endl;
            }
        }
    }

    // Close the file
    file.close();

    return 0;
}
