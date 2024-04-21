#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct Movie {
    string name;
    string genre;
    string language;
    string actorFirst;
    string actorLast;
    int movieDuration;
    int releaseYear;
};

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

unordered_map<string, Movie> readMoviesFromFile(const string& filePath) {
    ifstream file(filePath);
    unordered_map<string, Movie> movies;
    string line;

    if (!file.is_open()) {
        cerr << "Error: File could not be opened." << endl;
        return movies;
    }

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
            transform(movie.name.begin(), movie.name.end(), movie.name.begin(), ::tolower);
            movies[movie.name] = movie;
        }
    }

    file.close();
    return movies;
}

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

bool compareByReleaseYear(const Movie& a, const Movie& b) {
    return a.releaseYear > b.releaseYear;
}

int bubbleSortSearching() {
    string filePath = "Movies.csv"; // Specify your CSV file path here

    unordered_map<string, Movie> movies = readMoviesFromFile(filePath);
    vector<Movie> movieList;

    for (const auto& pair : movies) {
        movieList.push_back(pair.second);
    }

    bubbleSortMovies(movieList, compareByReleaseYear);

    for (const auto& movie : movieList) {
        cout << "Title: " << movie.name << ", Release Year: " << movie.releaseYear << endl;
    }

    return 0;
}
