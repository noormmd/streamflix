#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Plan.h"

TEST_CASE("Plan Display Test") {
    // Create a Plan object with sample data
    vector<string> planOptions = {"Standard", "Premium"};
    Plan plan(planOptions, true);

    SECTION("Valid Plan Display") {
        // Test displaying an existing plan
        stringstream output;
        stringstream expectedOutput;
        expectedOutput << "Plan Name: Basic" << endl;
        expectedOutput << "Available: Yes" << endl;

        // Redirect cout to a stringstream to capture output
        streambuf* oldCout = cout.rdbuf(output.rdbuf());
        plan.displayPlan("Basic");
        cout.rdbuf(oldCout); // Restore cout

        // Compare actual output with expected output
        REQUIRE(output.str() == expectedOutput.str());
    }

    SECTION("Invalid Plan Display") {
        // Test displaying a non-existent plan
        stringstream output;
        stringstream expectedOutput;
        expectedOutput << "Plan not found." << endl;

        // Redirect cout to a stringstream to capture output
        streambuf* oldCout = cout.rdbuf(output.rdbuf());
        plan.displayPlan("Standard"); // Assuming "Standard" plan does not exist
        cout.rdbuf(oldCout); // Restore cout

        // Compare actual output with expected output
        REQUIRE(output.str() == expectedOutput.str());
    }
}
