#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// here is the structure for a TV show
struct TVShow {
    string name;
    string genre;
    string language;
    int releaseYear;
    int season;
};

// this is the hash function for TVShow structure
struct TVShowHash {
    size_t operator()(const TVShow& show) const {

        // Hash  based on the combination of title, genre, and season
        return hash<string>()(show.name) ^ hash<string>()(show.genre) ^ hash<int>()(show.season);
    }
};


// here is the  equality function for TVShow structure
struct TVShowEqual {
    bool operator()(const TVShow& lhs, const TVShow& rhs) const {
        
        // here is the Equality based on the combination of title, genre, and season
        return lhs.name == rhs.name && lhs.genre == rhs.genre && lhs.season == rhs.season;
    }
};

int main() {
    // Creating a hash table for TV shows
    unordered_map<TVShow, int, TVShowHash, TVShowEqual> tvShows;

    // Add some TV shows to the hash table
    tvShows[{ "Suits", "Drama", "English", 2021, 9 }] = 134;
    tvShows[{ "Manifest", "Drama", "English", 2020,4 }] = 62;
    tvShows[{ "Brooklyn", "Comedy", "English", 2015, 1 }] = 12;
    tvShows[{ "Sweet Horror", "Horror", "Korean", 2023, 2 }] = 11;
    tvShows[{ "The innocent", "Thiller", "Spanish", 2020, 3 }] = 10;



 // Here are the  details for each TV show
    for (const auto& pair : tvShows) {
        const TVShow& show = pair.first;
        int episodes = pair.second;
        cout << "TV Show: " << show.name << endl;
        cout << "Genre: " << show.genre << endl;
        cout << "Language: " << show.language << endl;
        cout << "Release Year: " << show.releaseYear << endl;
        cout << "Season: " << show.season << endl;
        cout << "Number of Episodes: " << episodes << endl << endl;
    }
    
    return 0;
}






 