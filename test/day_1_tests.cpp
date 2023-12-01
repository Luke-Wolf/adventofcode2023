#include <catch.hpp>
#include "day_1.h"

namespace Day1 {
    TEST_CASE("Part 1: Basic 1 number") {
        REQUIRE(Solution::part_1("1") == 11);
        REQUIRE(Solution::part_2("1") == 11);
        REQUIRE(Solution::part_1("2") == 22);
        REQUIRE(Solution::part_2("2") == 22);
        REQUIRE(Solution::part_1("3") == 33);
        REQUIRE(Solution::part_2("3") == 33);
        REQUIRE(Solution::part_1("4") == 44);
        REQUIRE(Solution::part_2("4") == 44);
        REQUIRE(Solution::part_1("5") == 55);
        REQUIRE(Solution::part_2("5") == 55);
        REQUIRE(Solution::part_1("6") == 66);
        REQUIRE(Solution::part_2("6") == 66);
        REQUIRE(Solution::part_1("7") == 77);
        REQUIRE(Solution::part_2("7") == 77);
        REQUIRE(Solution::part_1("8") == 88);
        REQUIRE(Solution::part_2("8") == 88);
        REQUIRE(Solution::part_1("9") == 99);
        REQUIRE(Solution::part_2("9") == 99);
        REQUIRE(Solution::part_1("0") == 0);
        REQUIRE(Solution::part_2("0") == 0);
    }

    TEST_CASE("Part 1: Basic 2 number") {
        REQUIRE(Solution::part_1("12") == 12);
        REQUIRE(Solution::part_2("12") == 12);
    }

    TEST_CASE("Part 1: basic non-digit input test") {
        REQUIRE(Solution::part_1("1a") == 11);
        REQUIRE(Solution::part_2("1a") == 11);
        REQUIRE(Solution::part_1("a1") == 11);
        REQUIRE(Solution::part_2("a1") == 11);
        REQUIRE(Solution::part_1("a1a") == 11);
        REQUIRE(Solution::part_2("a1a") == 11);
    }

    TEST_CASE("Part 1: 1abc2 = 12") {
        REQUIRE(Solution::part_1("1abc2") == 12);
        REQUIRE(Solution::part_2("1abc2") == 12);
    }

    TEST_CASE("Part 1: pqr3stu8vwx = 38") {
        REQUIRE(Solution::part_1("pqr3stu8vwx") == 38);
        REQUIRE(Solution::part_2("pqr3stu8vwx") == 38);
    }

    TEST_CASE("Part 1: a1b2c3d4e5f = 15") {
        REQUIRE(Solution::part_1("a1b2c3d4e5f") == 15);
        REQUIRE(Solution::part_2("a1b2c3d4e5f") == 15);
    }

    TEST_CASE("Part 1: treb7uchet = 77") {
        REQUIRE(Solution::part_1("treb7uchet") == 77);
        REQUIRE(Solution::part_2("a1b2c3d4e5f") == 15);
    }

    TEST_CASE("Part 1: whole sample input") {
        const std::string input =
                "1abc2\n"
                "pqr3stu8vwx\n"
                "a1b2c3d4e5f\n"
                "treb7uchet\n";
        REQUIRE(Solution::part_1(input) == 142);
        REQUIRE(Solution::part_2(input) == 142);
    }

    TEST_CASE("Part 2: Written Numbers") {
        REQUIRE(Solution::part_2("one") == 11);
        REQUIRE(Solution::part_2("two") == 22);
        REQUIRE(Solution::part_2("three") == 33);
        REQUIRE(Solution::part_2("four") == 44);
        REQUIRE(Solution::part_2("five") == 55);
        REQUIRE(Solution::part_2("six") == 66);
        REQUIRE(Solution::part_2("seven") == 77);
        REQUIRE(Solution::part_2("eight") == 88);
        REQUIRE(Solution::part_2("nine") == 99);
    }

    TEST_CASE("Part 2: Partially Written Numbers") {
        REQUIRE(Solution::part_2("2oni") == 22);
        REQUIRE(Solution::part_2("1twe") == 11);
        REQUIRE(Solution::part_2("1threo") == 11);
        REQUIRE(Solution::part_2("1foum") == 11);
        REQUIRE(Solution::part_2("1fivu") == 11);
        REQUIRE(Solution::part_2("1siz") == 11);
        REQUIRE(Solution::part_2("1sevem") == 11);
        REQUIRE(Solution::part_2("1eighh") == 11);
        REQUIRE(Solution::part_2("1nino") == 11);

        REQUIRE(Solution::part_2("2on") == 22);
        REQUIRE(Solution::part_2("1tw") == 11);
        REQUIRE(Solution::part_2("1thre") == 11);
        REQUIRE(Solution::part_2("1fou") == 11);
        REQUIRE(Solution::part_2("1fiv") == 11);
        REQUIRE(Solution::part_2("1si") == 11);
        REQUIRE(Solution::part_2("1seve") == 11);
        REQUIRE(Solution::part_2("1eigh") == 11);
        REQUIRE(Solution::part_2("1nin") == 11);
    }

    TEST_CASE("Part 2: Basic Two numbers") {
        REQUIRE(Solution::part_2("one2") == 12);
        REQUIRE(Solution::part_2("1two") == 12);
        REQUIRE(Solution::part_2("onetwo") == 12);
    }

    TEST_CASE("Part 2: Basic non-digit test") {
        REQUIRE(Solution::part_2("aone") == 11);
        REQUIRE(Solution::part_2("onea") == 11);
        REQUIRE(Solution::part_2("aonea") == 11);
    }

    TEST_CASE("Part 2: Overlapping Numbers") {
        REQUIRE(Solution::part_2("oneight") == 18);
    }

    TEST_CASE("Part 2: two1nine = 29") {
        REQUIRE(Solution::part_2("two1nine") == 29);
    }

    TEST_CASE("Part2: eightwothree = 83") {
        REQUIRE(Solution::part_2("eightwothree") == 83);
    }

    TEST_CASE("Part2: abcone2threexyz = 13") {
        REQUIRE(Solution::part_2("abcone2threexyz") == 13);
    }

    TEST_CASE("Part2: xtwone3four = 24") {
        REQUIRE(Solution::part_2("xtwone3four") == 24);
    }

    TEST_CASE("Part2: 4nineeightseven2 = 42") {
        REQUIRE(Solution::part_2("4nineeightseven2") == 42);
    }

    TEST_CASE("Part2: zoneight234 = 14") {
        REQUIRE(Solution::part_2("zoneight234") == 14);
    }

    TEST_CASE("Part2: 7pqrstsixteen = 76") {
        REQUIRE(Solution::part_2("7pqrstsixteen") == 76);
    }

    TEST_CASE("Part2: Whole Input") {
        const std::string input =
                "two1nine\n"
                "eightwothree\n"
                "abcone2threexyz\n"
                "xtwone3four\n"
                "4nineeightseven2\n"
                "zoneight234\n"
                "7pqrstsixteen\n";
        REQUIRE(Solution::part_2(input) == 281);
    }
}