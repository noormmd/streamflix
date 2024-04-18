#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

// Defining the structure to represent a movie
struct Movie {
    string name;
    string genre;
    string language;
    string actorFirst;
    string actorLast;
    int movieDuration;
    int releaseYear;
};

// Function to trim leading and trailing whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Function to read movie data from a CSV file
unordered_map<string, Movie> readMoviesFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    unordered_map<string, Movie> movies;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(trim(token));
        }
        if (tokens.size() == 7) {
            Movie movie;
            movie.name = tokens[0];
            movie.genre = tokens[1];
            movie.language = tokens[2];
            movie.actorFirst = tokens[3];
            movie.actorLast = tokens[4];
            movie.movieDuration = stoi(tokens[5]);
            movie.releaseYear = stoi(tokens[6]);

            // Transform movie title to lowercase for case-insensitive search
            transform(movie.name.begin(), movie.name.end(), movie.name.begin(), ::tolower);

            movies[movie.name] = movie;
        }
    }

    file.close();
    return movies;
}

// Bubble sort function for vector of Movies
void bubbleSortMovies(vector<Movie>& movies, bool (*compare)(const Movie&, const Movie&)) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < movies.size() - 1; i++) {
            if (compare(movies[i], movies[i + 1])) {
                swap(movies[i], movies[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

// Comparator function to sort movies by release year
bool compareByReleaseYear(const Movie& a, const Movie& b) {
    return a.releaseYear > b.releaseYear; // Sort in descending order
}

// Main function to drive the program
int main() {
    unordered_map<string, Movie> movies = readMoviesFromCSV("Movies.csv");

    // Converting unordered_map to vector to sort
    vector<Movie> movieList;
    for (const auto& pair : movies) {
        movieList.push_back(pair.second);
    }

    // Sorting movies by release year using bubble sort
    bubbleSortMovies(movieList, compareByReleaseYear);

    // Print sorted movies
    for (const auto& movie : movieList) {
        cout << "Title: " << movie.name << ", Release Year: " << movie.releaseYear << endl;
    }

    return 0;
}
