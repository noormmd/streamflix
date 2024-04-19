<<<<<<< HEAD
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
    REQUIRE(testMovies.getActorFirst() == "Fist Name");
    REQUIRE(testMovies.getActorLast() == "Last Name");
    REQUIRE(testMovies.getMovieType() == "Genre");
    REQUIRE(testMovies.getMovieID() != 1);
    REQUIRE(testMovies.getMovieName() != "Title");
    REQUIRE(testMovies.getMovieID() != 1);
    REQUIRE(testMovies.getActorFirst() != "");
    REQUIRE(testMovies.getActorLast() != "");
    REQUIRE(testMovies.getMovieType() != "Genre");
}




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


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "YourRegistrationFunctions.hpp" // Include your header file containing registration functions

TEST_CASE("Email Validation", "[isValidEmail]") {
    SECTION("Valid email format") {
        REQUIRE(isValidEmail("abigail@gmail.com") == true);
        REQUIRE(isValidEmail("lucy@gmail.com") == true);
        REQUIRE(isValidEmail("rob@gmail.com") == true);
    }

    SECTION("Invalid email format") {
        REQUIRE(isValidEmail("invalid_email.com") == false);
        REQUIRE(isValidEmail("user@domain") == false);
        REQUIRE(isValidEmail("user123@.com") == false);
    }
}

TEST_CASE("User Registration", "[registerUser]") {
    // Create a temporary file for testing registration
    std::string testFilename = "test_users.csv";

    SECTION("Register new user") {
        std::string firstname = "Rob";
        std::string lastname = "James";
        std::string email = "rob@gmail.com";
        std::string password = "Rob123";

        // Register user
        registerUser(firstname, lastname, email, password, testFilename);

        // Check if user exists in the file
        REQUIRE(userExists(firstname, lastname, password, testFilename) == true);
    }

    SECTION("Register user with existing user") {
       std::string firstname = "Rob";
        std::string lastname = "James";
        std::string email = "rob@gmail.com";
        std::string password = "Rob123";




        // Register user with existing username
        registerUser(username, email, password, testFilename);

        // Try to register user with the same username again
        registerUser(username, "newemail@example.com", "newpassword123", testFilename);

        // Check if user still exists with the original username and password
        REQUIRE(userExists(username, password, testFilename) == true);
    }
}

TEST_CASE("User Existence Check", "[userExists]") {
    // Create a temporary file for testing
    std::string testFilename = "test_users.csv";

    SECTION("Check existing user") {
        // Assuming this user exists in the file
        std::string username = "existinguser";
        std::string password = "existingpassword";

        REQUIRE(userExists(username, password, testFilename) == true);
    }

    SECTION("Check non-existing user") {
        // Assuming this user doesn't exist in the file
        std::string username = "nonexistinguser";
        std::string password = "password123";

        REQUIRE(userExists(username, password, testFilename) == false);
    }
}
