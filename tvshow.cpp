#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // for std::swap

using namespace std;

//joshua code

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

// Function to partition the TV shows array for Quick Sort
int partition(vector<TVShow>& shows, int low, int high) {
    string pivot = shows[high].name; // Selecting the last element as the pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (shows[j].name <= pivot) {
            i++;
            swap(shows[i], shows[j]);
        }
    }
    swap(shows[i + 1], shows[high]);
    return i + 1;
}

// Quick Sort algorithm for sorting TV shows based on name
void quickSort(vector<TVShow>& shows, int low, int high) {
    if (low < high) {
        int pi = partition(shows, low, high);
        quickSort(shows, low, pi - 1);
        quickSort(shows, pi + 1, high);
    }
}

// Function to search for a specific TV show based on name using binary search
int binarySearch(const vector<TVShow>& shows, const string& target) {
    int low = 0;
    int high = shows.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (shows[mid].name == target)
            return mid;
        else if (shows[mid].name < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main() {
    // Read TV shows data from the CSV file
    ifstream file("tv-shows.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<TVShow> tvShows;

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
        // int releaseYear = stoi(releaseYearStr);
        // int season = stoi(seasonStr);

         int releaseYear, season;
try {
    cout << "releaseYearStr: " << releaseYearStr << endl;
    cout << "seasonStr: " << seasonStr << endl;
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

        // Create a TVShow object and add it to the vector
        TVShow show(name, genre, language, releaseYear, season);
        tvShows.push_back(show);
    }
    file.close();

    // Sort TV shows based on name
    quickSort(tvShows, 0, tvShows.size() - 1);

    // Prompt user to enter the name of the TV show to search for
    cout << "Enter the name of the TV show to search for: ";
    string searchTerm;
    getline(cin, searchTerm);

    // Perform binary search to find the TV show
    int index = binarySearch(tvShows, searchTerm);
    if (index != -1) {
        cout << "TV Show found at index: " << index << endl;
        cout << "Details:" << endl;
        cout << "Name: " << tvShows[index].name << endl;
        cout << "Genre: " << tvShows[index].genre << endl;
        cout << "Language: " << tvShows[index].language << endl;
        cout << "Release Year: " << tvShows[index].releaseYear << endl;
        cout << "Season: " << tvShows[index].season << endl;
    } else {
        cout << "TV Show not found." << endl;
    }

    return 0;
}
