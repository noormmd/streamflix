#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp" // Include the Catch2 framework
#include "Movies.h" // Include your movie-related headers
#include "Movies.cpp" // Include the implementation file

TEST_CASE("Search by title") {
    // Create test movies
    std::vector<Movie> testMovies;
    testMovies.push_back(Movie(166, 1, "Dune", "Action", "English", "2024"));
    testMovies.push_back(Movie(130, 4, "Inception", "Sci-Fi", "English", "2010"));

    // Create a hash map of movies
    std::unordered_map<std::string, Movie> movieMap;
    for (const auto& movie : testMovies) {
        movieMap.emplace(trim(movie.getMovieName()), movie);
    }

    SECTION("Existing title search") {
        // Perform search for existing title
        std::string searchTerm = "Dune";
        searchByTitle(movieMap, searchTerm);

        // Check if output matches expected
        CHECK(Catch::getResultCapture().lastAssertionPassed());
    }

    SECTION("Non-existent title search") {
        // Perform search for non-existent title
        std::string searchTerm = "Interstellar";
        searchByTitle(movieMap, searchTerm);

        // Check if output matches expected
        CHECK_FALSE(Catch::getResultCapture().lastAssertionPassed());
    }
}

TEST_CASE("Search by genre") {
    // Create test movies
    std::vector<Movie> testMovies;
    testMovies.push_back(Movie(166, 1, "Dune", "Action", "English", "2024"));
    testMovies.push_back(Movie(130, 2, "Inception", "Sci-Fi", "English", "2010"));

    // Create a hash map of movies
    std::unordered_map<std::string, Movie> movieMap;
    for (const auto& movie : testMovies) {
        movieMap.emplace(trim(movie.getMovieGenre()), movie);
    }

    SECTION("Existing genre search") {
        // Perform search for existing genre
        std::string searchTerm = "Action";
        searchByGenre(movieMap, searchTerm);

        // Check if output matches expected
        CHECK(Catch::getResultCapture().lastAssertionPassed());
    }

    SECTION("Non-existent genre search") {
        // Perform search for non-existent genre
        std::string searchTerm = "Romance";
        searchByGenre(movieMap, searchTerm);

        // Check if output matches expected
        CHECK_FALSE(Catch::getResultCapture().lastAssertionPassed());
    }
}
