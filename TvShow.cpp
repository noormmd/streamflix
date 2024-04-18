#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// here is the structure for a TV show
struct TVShow {
    string name;
    string genre;
    string language;
    int releaseYear;
    int season;
};

// this is the Function to compare TVShows based on release year
bool compareByReleaseYear(const TVShow& a, const TVShow& b) {
    return a.releaseYear < b.releaseYear;
}

// here we can find the bubble sort algorithm to sort TVShows based on release year
void bubbleSort(vector<TVShow>& shows) {
    int n = shows.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareByReleaseYear(shows[j], shows[j + 1])) {
                swap(shows[j], shows[j + 1]);
            }
        }
    }
}

int main() {
    // this part is creating a vector to store TV shows
    vector<TVShow> tvShows;

    // Adding some TV shows to the vector
    tvShows.push_back({ "Suits", "Drama", "English", 2021, 9 });
    tvShows.push_back({ "Manifest", "Drama", "English", 2020, 4 });
    tvShows.push_back({ "Brooklyn", "Comedy", "English", 2015, 1 });
    tvShows.push_back({ "Sweet Horror", "Horror", "Korean", 2023, 2 });
    tvShows.push_back({ "The innocent", "Thiller", "Spanish", 2020, 3 });

    // Sort the TV shows using bubble sort based on release year
    bubbleSort(tvShows);

    // Print the sorted TV shows
    for (const auto& show : tvShows) {
        cout << "TV Show: " << show.name << endl;
        cout << "Genre: " << show.genre << endl;
        cout << "Language: " << show.language << endl;
        cout << "Release Year: " << show.releaseYear << endl;
        cout << "Season: " << show.season << endl;
        cout << endl;
    }

    return 0;
}
