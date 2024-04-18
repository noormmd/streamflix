#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm> 

using namespace std;

// Structure for TV show
struct TVShow {
    string name;
    string genres; 
    string language;
    int releaseYear;
    int season;


    // Constructor to initialize the TV show
    TVShow(string name, string genres, string language, int releaseYear, int season) :
        name(name), genres(genres), language(language), releaseYear(releaseYear), season(season) {}
};

/**
// Function to trim leading and trailing whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}
*/

std::vector<TVShow> readShowsFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<TVShow> tvShows;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return tvShows;
    }

    std::string line;
    getline(file, line);
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, genres, language, releaseYearStr, seasonStr;
        getline(ss, name, ',');
        getline(ss, genres, ',');
        getline(ss, language, ',');
        getline(ss, releaseYearStr, ',');
        getline(ss, seasonStr, ',');

        // Convert string to integer
        int releaseYear, season;
        try {
            if (!releaseYearStr.empty() && !seasonStr.empty()) {
                releaseYear = std::stoi(releaseYearStr);
                season = std::stoi(seasonStr);
            } else {
                std::cerr << "Error: Empty value encountered for release year or season." << std::endl;
                continue; // Skip line
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid integer value encountered in CSV." << std::endl;
            continue; 
        }

        // Create a TVShow object and add it to the vector
        TVShow show(name, genres, language, releaseYear, season);
        tvShows.push_back(show);
    }

    file.close();
    return tvShows;
}