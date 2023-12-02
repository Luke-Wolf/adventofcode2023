#ifndef ADVENTOFCODE2023_DAY_2_H
#define ADVENTOFCODE2023_DAY_2_H

#include <cstdint>
#include <string>
#include <vector>

namespace Day2 {
    class Draw {
    public:
        int32_t red;
        int32_t green;
        int32_t blue;
    };

    class Game {
    public:
        int32_t number;
        std::vector<Draw> draws;
    };

    class Solution {
    public:
        /**
         * Determine whether a game is possible based on the number of cubes drawn
         * then add the Ids of the games together
         * @param Input a string of the format: Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
         * @param number_of_cubes the number of cubes of each color to compare to
         * @return the sum of the valid game ids
         */
        auto static part_1(const std::string &Input, const Draw &number_of_cubes) -> int32_t;

        /**
         * Determine the minimum number of cubes required to match a particular game
         * then multiply the number of cubes together and sum the results together
         * @param Input a string of the format: Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
         * @return the sum  of the result of multiplying all the cubes together for each game
         */
        auto static part_2(const std::string &Input) -> int32_t;

    private:

        auto static parse_game(const std::string &Line) -> Game;

        auto static parse_round(const std::string &game) -> Draw;

        auto static draw_possible(const Draw &basis, const Draw &from_round) -> bool;
    };

}
#endif //ADVENTOFCODE2023_DAY_2_H
