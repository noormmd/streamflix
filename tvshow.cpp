#include "TVshows.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm> 

using namespace std;


// Function to read TV shows from CSV file
std::vector<TVShow> readShowsFromCSV(const std::string& showsfilename) {
    std::ifstream file(showsfilename);

    std::vector<TVShow> tvShows;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << showsfilename << std::endl;
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