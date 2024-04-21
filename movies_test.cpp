#include "Movies.h"
#include <iostream>
#include <vector>
#include "Movies.cpp"

int testformovies() {
    // Read movies from CSV file
    std::vector<Movie> movies = readMoviesFromCSV("Movies.csv");

    // Print details of each movie
    for (const auto& movie : movies) {
        movie.printDetails();
        std::cout << std::endl;
    }

    return 0;
}
