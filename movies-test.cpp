#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "movies.h"

TEST_CASE("Test Movie Class") {
    // Create a movie object
    Movie movie(166, 1, "Dune", "Action", "Timothee", "Chalamet");

    SECTION("Test getters") {
        REQUIRE(movie.getMovieID() == "1");
        REQUIRE(movie.getMovieName() == "Dune");
        REQUIRE(movie.getMovieGenre() == "Action");
        REQUIRE(movie.getActorFirst() == "Timothee");
        REQUIRE(movie.getActorLast() == "Chalamet");
        REQUIRE(movie.getMovieDuration() == 166);
        // Add more REQUIRE statements for other getters if needed
    }

    SECTION("Test printDetails method") {
        // Redirect cout to a stringstream
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        // Call the printDetails method
        movie.printDetails();

        // Get the printed output
        std::string output = buffer.str();

        // Reset cout
        std::cout.rdbuf(old);

        // Check if the printed output matches the expected format
        REQUIRE(output == "Movie ID: 1\nMovie Name: Dune\nGenre: Action\nStarring: Timothee Chalamet\nDuration: 166 minutes\n");
    }
}
