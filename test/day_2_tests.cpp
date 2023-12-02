#include "day_2.h"
#include <catch.hpp>

namespace Day2 {
    TEST_CASE("Part 1: 1 draw, 1 value, 1 cube in bag") {
        REQUIRE(Solution::part_1("Game 1: 1 red", Draw{0, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red", Draw{1, 0, 0}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 red", Draw{1, 0, 0}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 blue", Draw{0, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 blue", Draw{0, 0, 1}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 blue", Draw{0, 0, 1}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 green", Draw{0, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 green", Draw{0, 1, 0}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 green", Draw{0, 1, 0}) == 3);

    }

    TEST_CASE("Part 1: 1 draw, 1 value, multiple cubes in bag") {
        REQUIRE(Solution::part_1("Game 1: 1 red", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 red", Draw{1, 1, 1}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 blue", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 blue", Draw{1, 1, 1}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 green", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 green", Draw{1, 1, 1}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 red", Draw{2, 2, 2}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 red", Draw{1, 1, 1}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 blue", Draw{2, 2, 2}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 blue", Draw{2, 2, 2}) == 3);

        REQUIRE(Solution::part_1("Game 1: 1 green", Draw{2, 2, 2}) == 1);
        REQUIRE(Solution::part_1("Game 3: 1 green", Draw{2, 2, 2}) == 3);
    }

    TEST_CASE("Part 1: 1 draw, multiple value, single cube in bag") {
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{1, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{0, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{0, 0, 1}) == 0);

        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{1, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{0, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{0, 0, 1}) == 0);

        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{1, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{0, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{0, 0, 1}) == 0);

        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{1, 0, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{0, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{0, 0, 1}) == 0);
    }

    TEST_CASE("Part 1: 1 draw, multiple value, multiple cube in bag") {
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{1, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{1, 0, 1}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green, 1 blue", Draw{0, 1, 1}) == 0);

        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{1, 1, 0}) == 1);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{1, 0, 1}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 green", Draw{0, 1, 1}) == 0);

        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{1, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{1, 0, 1}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 green, 1 blue", Draw{0, 1, 1}) == 1);

        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{1, 1, 1}) == 1);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{1, 1, 0}) == 0);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{1, 0, 1}) == 1);
        REQUIRE(Solution::part_1("Game 1: 1 red, 1 blue", Draw{0, 1, 1}) == 0);
    }

    TEST_CASE("Part 1: Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green") {
        REQUIRE(Solution::part_1("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green", Draw{12, 13, 14}) == 1);
    }

    TEST_CASE("Part 1: Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue") {
        REQUIRE(Solution::part_1("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
                                 Draw{12, 13, 14}) ==
                2);
    }

    TEST_CASE("Part 1: Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red") {
        REQUIRE(Solution::part_1("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
                                 Draw{12, 13, 14}) == 0);
    }

    TEST_CASE("Part 1: Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red") {
        REQUIRE(Solution::part_1("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
                                 Draw{12, 13, 14}) == 0);
    }

    TEST_CASE("Part 1: Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green") {
        REQUIRE(Solution::part_1("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", Draw{12, 13, 14}) ==
                5);
    }

    TEST_CASE("Part1: multi-game example input") {
        const std::string input =
                "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n"
                "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n"
                "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n"
                "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n"
                "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green\n";
        REQUIRE(Solution::part_1(input, Draw{12, 13, 14}) == 8);
    }

    TEST_CASE("Part 2: Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green = 48") {
        REQUIRE(Solution::part_2("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green = 12") == 48);
    }

    TEST_CASE("Part 2: Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue = 12") {
        REQUIRE(Solution::part_2("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue") == 12);
    }

    TEST_CASE("Part 2: Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red = 1560") {
        REQUIRE(Solution::part_2("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red") == 1560);
    }

    TEST_CASE("Part 2: Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red = 630") {
        REQUIRE(Solution::part_2("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red") == 630);
    }

    TEST_CASE("Part 2: Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green = 36") {
        REQUIRE(Solution::part_2("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green") == 36);
    }

    TEST_CASE("Part 2: multi-game example input") {
        const std::string input =
                "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n"
                "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n"
                "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n"
                "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n"
                "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green\n";
        REQUIRE(Solution::part_2(input) == 2286);
    }

}