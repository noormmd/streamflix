#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Users.h"

TEST_CASE("User Class Test Cases", "[User]") {
    SECTION("Constructing a User Object") {
        User user("Rob", "rob@gmail.com", "Rob123");

        REQUIRE(user.getUsername() == "Rob");
        REQUIRE(user.getEmail() == "rob@gmail.com");
        REQUIRE(user.getPassword() == "Rob123");
    }

    SECTION("Setting and Retrieving Selected Plan") {
        User user("Tom", "tom@gmail.com", "Tom123");

        user.setSelectedPlan("Premium");
        REQUIRE(user.getSelectedPlan() == "Premium");

        user.setSelectedPlan("Standard");
        REQUIRE(user.getSelectedPlan() == "Standard");
    }

    SECTION("Reading Users from CSV") {
        // Prepare a CSV file with sample user data
        std::ofstream outfile("test_users.csv");
        outfile << "Rob, rob@gmail.com, Rob123, Premium\n";
        outfile << "Tom, tom@gmail.com, Tom123,Standard\n";
        outfile.close();

        // Read users from the CSV file
        vector<User> users = readUsersFromCSV("users.csv");

        // Verify the contents of the vector
        REQUIRE(users.size() == 2);
        REQUIRE(users[0].getUsername() == "Rob");
        REQUIRE(users[0].getEmail() == "rob@gmail.com");
        REQUIRE(users[0].getPassword() == "Rob123");
        REQUIRE(users[0].getSelectedPlan() == "Premium");
        REQUIRE(users[1].getUsername() == "Tom");
        REQUIRE(users[1].getEmail() == "tom@gmail.com");
        REQUIRE(users[1].getPassword() == "Tom123");
        REQUIRE(users[1].getSelectedPlan() == "Standard");

        
    }