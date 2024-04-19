#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include Movies.h
#include TVshows.h
#include Users.h
#include Plan.h

// Test cases.

TEST_CASE("movies", "[movies]")
{
    Movies testMovies(1, "Title", "actorFirst", "actorLast", "Genre", "Language", "ReleaseYear");
    REQUIRE(testMovies.getMovieID() == 1);
    REQUIRE(testMovies.getMovieName() == "Title");
    REQUIRE(testMovies.getActorFirst() == "First Name");
    REQUIRE(testMovies.getActorLast() == "Last Name");
    REQUIRE(testMovies.getMovieType() == "Genre");
    REQUIRE(testMovies.getMovieID() != 1);
    REQUIRE(testMovies.getMovieName() != "Title");
    REQUIRE(testMovies.getMovieID() != 1);
    REQUIRE(testMovies.getActorFirst() != "First Name");
    REQUIRE(testMovies.getActorLast() != "Last Name");
    REQUIRE(testMovies.getMovieType() != "Genre");
}

c




TEST_CASE("tvshow", "[tvshow]")
{
    TVshows testTVshows(1, "Title", "actorFirst", "actorLast", "Genre", "Language", "ReleaseYear");
    REQUIRE(testTVshows.getTvShowID() == 1);
    REQUIRE(testTVshows.getTvShowName() == "Title");
    REQUIRE(testTVshows.getActorFirst() == "");
    REQUIRE(testTVshows.getActorLast() == "");
    REQUIRE(testTVshows.getMovieType() == "Genre");
    REQUIRE(testTVshows.getMovieName() != "Title");
    REQUIRE(testTVshows.getActorFirst() != "");
    REQUIRE(testTVshows.getActorLast() != "");
    REQUIRE(testTVshows.getMovieType() != "Genre");
}



TEST_CASE("users", "[users]")
{
    Users testUsers(1, "Title", "userFirst", "userLast", "Plan", "Email", "Password");
    REQUIRE(testUsers.getTvShowID() == 1);
    REQUIRE(testUsers.getTvShowName() == "Title");
    REQUIRE(testUsers.getUserFirst() == "First Name");
    REQUIRE(testUsers.getUserLast() == "Last Name");
    REQUIRE(testUsers.getPlanType() == "Plan");
    REQUIRE(testUsers.getEmail() == "E-Mail Address");
    REQUIRE(testUsers.getPassword() == "Password");
    REQUIRE(testUsers.getUserID() != 1);
    REQUIRE(testUsers.getUserName() != "Title");
    REQUIRE(testUsers.getUserFirst() != " First Name");
    REQUIRE(testUsers.getUserLast() != "Last Name");
    REQUIRE(testUsers.getEmail() == "E-Mail Address");
    REQUIRE(testUsers.getPlanType() != "Plan");
    REQUIRE(testUsers.getEmail() == "E-Mail Address");
    REQUIRE(testUsers.getPassword() == "Password");
}

