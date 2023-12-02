#include "day_2.h"
#include <algorithm>
#include <sstream>

namespace Day2 {
    auto Solution::part_1(const std::string &Input, const Draw &number_of_cubes) -> int32_t {
        std::stringstream stream{Input};
        std::vector<Game> games;
        while (!stream.eof()) {
            std::string line;
            std::getline(stream, line);
            if (!line.empty()) {
                games.push_back(parse_game(line));
            }
        }
        int32_t result = 0;
        for (const auto &game: games) {
            if (std::all_of(game.draws.cbegin(), game.draws.cend(),
                            [number_of_cubes](Draw draw) { return Solution::draw_possible(number_of_cubes, draw); })) {
                result += game.number;
            }
        }
        return result;
    }

    auto Solution::part_2(const std::string &Input) -> int32_t {
        std::stringstream stream{Input};
        std::vector<Game> games;
        while (!stream.eof()) {
            std::string line;
            std::getline(stream, line);
            if (!line.empty()) {
                games.push_back(parse_game(line));
            }
        }
        int32_t result = 0;
        for (const auto &game: games) {
            int32_t red = 0;
            int32_t green = 0;
            int32_t blue = 0;
            for (const auto &draw: game.draws) {
                red = std::max(red, draw.red);
                green = std::max(green, draw.green);
                blue = std::max(blue, draw.blue);
            }
            result += red * green * blue;
        }

        return result;
    }

    auto Solution::parse_game(const std::string &Line) -> Game {
        std::stringstream stream{Line};
        std::string game_string;
        std::getline(stream, game_string, ':');
        std::stringstream game_stream{game_string};
        std::string temp;
        int32_t game;
        game_stream >> temp >> game;

        std::vector<Draw> draws;
        while (!stream.eof()) {
            temp.clear();
            std::getline(stream, temp, ';');
            draws.push_back(parse_round(temp));
        }
        return Game{game, draws};
    }

    auto Solution::parse_round(const std::string &round) -> Draw {
        std::vector<std::string> color_lines;
        std::stringstream colors{round};
        std::string temp;
        while (!colors.eof()) {
            std::getline(colors, temp, ',');
            color_lines.push_back(temp);
            temp.clear();
        }

        int32_t red = 0;
        int32_t blue = 0;
        int32_t green = 0;
        for (const auto &line: color_lines) {
            int32_t temp_num = 0;
            std::stringstream linestream{line};
            linestream >> temp_num >> temp;
            if (temp == "red") {
                red = temp_num;
            } else if (temp == "blue") {
                blue = temp_num;
            } else if (temp == "green") {
                green = temp_num;
            }
        }
        return Draw{red, green, blue};
    }

    auto Solution::draw_possible(const Draw &basis, const Draw &from_round) -> bool {
        return basis.red >= from_round.red && basis.blue >= from_round.blue && basis.green >= from_round.green;
    }

}