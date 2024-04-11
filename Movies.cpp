#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm> 

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
    unordered_map<string, Movie> movies;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return movies;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 7) { 
            Movie movie;
            movie.name = trim(tokens[0]);
            movie.genre = trim(tokens[1]);
            movie.language = trim(tokens[2]);
            movie.actorFirst = trim(tokens[3]);
            movie.actorLast = trim(tokens[4]);
            movie.movieDuration = stoi(trim(tokens[5]));
            movie.releaseYear = stoi(trim(tokens[6]));

            //  to transform movie title to lowercase for case-insensitive search
            transform(movie.name.begin(), movie.name.end(), movie.name.begin(), ::tolower);

            movies[movie.name] = movie;
        }
    }

    file.close();
    return movies;
}

//  a function to search for movies by title in a hash map
void searchByTitle(const unordered_map<string, Movie>& movies, const string& title) {
    string searchTerm = trim(title);
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);

    auto it = movies.find(searchTerm);
    if (it != movies.end()) {
        cout << "Movie found: " << endl;
        cout << "Title: " << it->second.name << endl;
        cout << "Genre: " << it->second.genre << endl;
        cout << "Language: " << it->second.language << endl;
        cout << "Release Year: " << it->second.releaseYear << endl;
    } else {
        cout << "Movie with title '" << title << "' not found." << endl;
    }
}

// a function to search for movies by genre in a hash map
void searchByGenre(const unordered_map<string, Movie>& movies, const string& genre) {
    string searchTerm = trim(genre);
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);

    bool found = false;
    for (const auto& pair : movies) {
        string movieGenreLower = pair.second.genre;
        transform(movieGenreLower.begin(), movieGenreLower.end(), movieGenreLower.begin(), ::tolower);
        if (movieGenreLower == searchTerm) {
            cout << "Movie found: " << endl;
            cout << "Title: " << pair.second.name << endl;
            cout << "Genre: " << pair.second.genre << endl;
            cout << "Language: " << pair.second.language << endl;
            cout << "Release Year: " << pair.second.releaseYear << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No movies found in genre '" << genre << "'." << endl;
    }
}

int main() {
    // Read movies from CSV file
    unordered_map<string, Movie> movies = readMoviesFromCSV("movies.csv");

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
}