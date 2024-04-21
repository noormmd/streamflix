#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Plan.h"

TEST_CASE("Plan Class Test Cases") {
    SECTION("Constructing a Plan Object") {
        vector<string> options = { "Standard", "Premium"};
        Plan plan(9.99, options, true);

        REQUIRE(plan.totalPrice(1) == 9.99f);
        REQUIRE(plan.isAvailable() == true);
    }

    SECTION("Calculating Total Price") {
        vector<string> options = {"Standard", "Premium"};
        Plan plan(9.99, options, true);

        // Total price for 6-month subscription
        REQUIRE(plan.totalPrice(6) == Approx(59.94).margin(0.01));

        // Total price for 0-month subscription (edge case)
        REQUIRE(plan.totalPrice(0) == 0.0f);
    }

    SECTION("Check Plan Availability") {
        vector<string> options = {"Basic", "Standard", "Premium"};
        Plan plan(9.99, options, true);

        REQUIRE(plan.isAvailable() == true);

        // Change plan availability
        // plan.setAvailability(false); // Uncomment if setAvailability is implemented
        // REQUIRE(plan.isAvailable() == false);
    }

    SECTION("Edge Case: Empty Plan Options") {
        vector<string> options; // Empty plan options
        Plan plan(0.0, options, true);

        // Total price for 12-month subscription with empty plan options
        REQUIRE(plan.totalPrice(12) == Approx(0.0).margin(0.01));
    }

    SECTION("Edge Case: Negative Price") {
        vector<string> options = {"Standard", "Premium"};
        Plan plan(-5.0, options, true);

        // Total price for 3-month subscription with negative price
        REQUIRE(plan.totalPrice(3) == Approx(-15.0).margin(0.01));
    }
}