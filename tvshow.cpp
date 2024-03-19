#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Structure for TV show
struct TVShow {
    string name;
    string genre;
    string language;
    int releaseYear;
    int season;

    // Constructor to initialize the TV show
    TVShow(string name, string genre, string language, int releaseYear, int season) : 
        name(name), genre(genre), language(language), releaseYear(releaseYear), season(season) {}
};

int main() {
    // Read TV shows data from the CSV file
    ifstream file("tv-shows.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Define a hash table to store TV shows
    unordered_map<string, TVShow> tvShows;

    string line;
    getline(file, line); // Skip header line
    while (getline(file, line)) {
        stringstream ss(line);
        string name, genre, language, releaseYearStr, seasonStr;
        getline(ss, name, ',');
        getline(ss, genre, ',');
        getline(ss, language, ',');
        getline(ss, releaseYearStr, ',');
        getline(ss, seasonStr, ',');

        // Convert string to integer
        int releaseYear, season;
        try {
            if (!releaseYearStr.empty() && !seasonStr.empty()) {
                releaseYear = stoi(releaseYearStr);
                season = stoi(seasonStr);
            } else {
                cerr << "Error: Empty value encountered for release year or season." << endl;
                continue; // Skip this line and move to the next one
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error: Invalid integer value encountered in CSV." << endl;
            continue; // Skip this line and move to the next one
        }

        // Create a TVShow object and add it to the hash table
        TVShow show(name, genre, language, releaseYear, season);
        tvShows[name] = show;
    }
    file.close();

    // Prompt user to enter the name of the TV show to search for
    cout << "Enter the name of the TV show to search for: ";
    string searchTerm;
    getline(cin, searchTerm);

    // Search for the TV show in the hash table
    auto it = tvShows.find(searchTerm);
    if (it != tvShows.end()) {
        cout << "TV Show found: " << endl;
        cout << "Name: " << it->second.name << endl;
        cout << "Genre: " << it->second.genre << endl;
        cout << "Language: " << it->second.language << endl;
        cout << "Release Year: " << it->second.releaseYear << endl;
        cout << "Season: " << it->second.season << endl;
    } else {
        cout << "TV Show not found." << endl;
    }

    return 0;
}
