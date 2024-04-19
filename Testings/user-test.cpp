#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Users.h" // Assuming this is the header file containing the User class
#include "Plan.h" // Assuming this is the header file containing the Plan class


TEST_CASE("User Class Test Cases") {
    SECTION("Constructing a User Object") {
        User user("Rob", "James", "rob@gmail.com", "Rob123");

        REQUIRE(user.getFirstname() == "Rob");
        REQUIRE(user.getLastname() == "James");
        REQUIRE(user.getEmail() == "rob@gmail.com");
        REQUIRE(user.getPassword() == "Rob123");
    }

    SECTION("Setting and Retrieving Selected Plan") {
        User user("Abigail", "Smith","abigail@gmail.com", "Abigail123")
        user.setSelectedPlan("Premium");
        REQUIRE(user.getSelectedPlan() == "Premium");

        user.setSelectedPlan("Standard");
        REQUIRE(user.getSelectedPlan() == "Standard");
    }


    SECTION("Updating Email") {
        User user("Lucy","Wright","lucy@gmail.com","Lucy123");

        // Update email
        user.setEmail("lucy@gmail.com");
        REQUIRE(user.getEmail() == "lucy@gmail.com");
    }

    SECTION("Changing Password") {
        User user("Tom", "Lane", "tom@gmail.com", "oldpassword");

        // Change password
        user.setPassword("newpassword");
        REQUIRE(user.getPassword() == "newpassword");
    }
}

// Test cases for reading and writing user information from/to CSV
TEST_CASE("Read and Write Users to CSV") {
    SECTION("Read Users from CSV") {
        string filename = "users.csv"; // Provide the path to a valid CSV file for testing
        // Call the function to read users from CSV
        vector<User> users = readUsersFromCSV(users.csv);
        // Check if the number of users read matches the expected number
        REQUIRE(users.size() == 5); // Assuming there are 5 users in the test CSV file
        // Check the details of each user
        REQUIRE(users[0].getUserId() == 1);
        REQUIRE(users[0].getFirstName() == "Rob");
        REQUIRE(users[0].getLastName() == "James");
        REQUIRE(users[0].getPlanType() == "Premium");
        REQUIRE(users[0].getEmail() == "rob@gmail.com");
        REQUIRE(users[0].getPassword() == "Rob123");
        // Add more REQUIRE statements to check other user details
    }


}





