#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "movies.h"

TEST_CASE("Test Movie class functionality", "[Movie]")
{
    Movie movie(1, 166, "Dune", "Action", "Timothee", "Chalamet");

    SECTION("Test getters")
    {
        REQUIRE(movie.getMovieID() == 1);
        REQUIRE(movie.getMovieName() == "Dune");
        REQUIRE(movie.getActorFirst() == "Timothee");
        REQUIRE(movie.getActorLast() == "Chalamet");
        REQUIRE(movie.getMovieDuration() == 166);
        REQUIRE(movie.getMovieGenre() == "Action");
    }

    SECTION("Test printDetails")
    {
        std::ostringstream output;
        std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf()); // Redirect cout
        movie.printDetails();
        std::cout.rdbuf(oldCout); // Restore cout

        std::string expectedOutput = "Movie ID: 1\n"
                                     "Movie Name: Dune\n"
                                     "Genre: Action\n"
                                     "Starring: Timothee Chalamet\n"
                                     "Duration: 166 minutes\n";

        REQUIRE(output.str() == expectedOutput);
    }
}
