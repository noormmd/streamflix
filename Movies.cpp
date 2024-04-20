#include "Movies.h" // Including the header file for movies

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm> 

using namespace std;

// Function to trim leading and trailing whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Function to read movie data from a CSV file and return as vector of movie objects
std::vector<Movie> readMoviesFromCSV(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<Movie> movies;

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return movies;
    }

    std::string line;
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        if (tokens.size() == 7)
        {
             // Convert string tokens to integers
            int duration = std::stoi(tokens[0]);
            int id = std::stoi(tokens[1]);
            int releaseYear = std::stoi(tokens[6]);

            // Create Movie object
            Movie movie(duration, id, tokens[2], tokens[3], tokens[4], tokens[5]);
            movies.push_back(movie);
        }
    }

    file.close();
    return movies;
}

//  Function to search for movies by title in a hash map
void searchByTitle(const unordered_map<string, Movie>& movies, const string& title) {
    string searchTerm = trim(title);
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);

    auto it = movies.find(searchTerm);
    if (it != movies.end()) {
        cout << "Movie found: " << endl;
        cout << "Title: " << it->second.getMovieName() << endl;
        cout << "Genre: " << it->second.getMovieGenre() << endl;
        cout << "Language: " << it->second.getMovieLanguage() << endl;
        cout << "Release Year: " << it->second.getReleaseYear() << endl;
    } else {
        cout << "Movie with title '" << title << "' not found." << endl;
    }
}

// Function to search for movies by genre in a hash map
void searchByGenre(const unordered_map<string, Movie>& movies, const string& genre) {
    string searchTerm = trim(genre);
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);

    bool found = false;
    for (const auto& pair : movies) {
        string movieGenreLower = pair.second.getMovieGenre();
        transform(movieGenreLower.begin(), movieGenreLower.end(), movieGenreLower.begin(), ::tolower);
        if (movieGenreLower == searchTerm) {
            cout << "Movie found: " << endl;
            cout << "Title: " << pair.second.getMovieName() << endl;
            cout << "Genre: " << pair.second.getMovieGenre() << endl;
            cout << "Language: " << pair.second.getMovieLanguage() << endl;
            cout << "Release Year: " << pair.second.getReleaseYear() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No movies found in genre '" << genre << "'." << endl;
    }
}

/**
int main() {
    // Read movies from CSV file
    unordered_map<string, Movie> movies = readMoviesFromCSV("Movies.csv");

    // Prompt user to choose search criteria
    cout << "Choose search criteria:" << endl;
    cout << "1. Search by title" << endl;
    cout << "2. Search by genre" << endl;
    int choice;
    cin >> choice;
    cin.ignore(); // Ignore newline character in input buffer

    // Perform search based on user choice
    if (choice == 1) {
        // Prompt user to enter the name of the movie to search for
        cout << "Enter the name of the movie to search for: ";
        string searchTerm;
        getline(cin, searchTerm);
        searchByTitle(movies, searchTerm);
    } else if (choice == 2) {
        // Prompt user to enter the genre to search for
        cout << "Enter the genre of the movie to search for: ";
        string searchGenre;
        getline(cin, searchGenre);
        searchByGenre(movies, searchGenre);
    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }

    return 0;
}*/