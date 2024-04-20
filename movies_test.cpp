#include "Movies.h" 
#include <iostream>
#include <vector>

int main() {
    // Read movies from CSV file
    std::vector<Movie> movies = readMoviesFromCSV("Movies.csv");

    // Print details of each movie
    for (const auto& movie : movies) {
        movie.printDetails();
        std::cout << std::endl;
    }

    return 0;
}
