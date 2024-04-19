#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "TVshows.h"

TEST_CASE("Testing TVshows class") {
    // Define test data
    int duration = 45;
    int id = 1;
    std::string name = "Suits";
    std::string genre = "Drama";
    std::string first = "Gabriel";
    std::string last = "Macht";
    int seasons = 9;
    std::vector<int> episodes = {10, 12, 14, 13, 15, 16, 13, 14, 15};
    std::vector<std::string> genreList = {"Drama"};

    TVshows tvShow(duration, id, name, genre, first, last, seasons, episodes, genreList);

    SECTION("Test getSeasonCount() method") {
        REQUIRE(tvShow.getSeasonCount() == 9);
    }

    SECTION("Test getEpisodeCount() method") {
        REQUIRE(tvShow.getEpisodeCount() == 9); // Total number of episodes
    }
}
