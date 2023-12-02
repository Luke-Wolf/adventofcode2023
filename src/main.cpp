#include <cstdint>
#include <format>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "day_1.h"
#include "day_2.h"

auto read_file(std::string path) -> std::string {
    std::string result;
    std::fstream stream{path};
    while (!stream.eof()) {
        std::string line;
        std::getline(stream, line);
        result += line + "\n";
    }
    return result;
}


auto main(int argc, char *argv[]) -> int {
    if (argc != 3) {
        std::cout << std::format("USAGE: DAY InputFile.txt") << "\n";
    }

    const auto num = atoi(argv[1]);
    const auto input = read_file(argv[2]);
    switch (num) {
        case 1 :
            std::cout << std::format("Day 1 Part 1 Result: {}\n", Day1::Solution::part_1(input));
            std::cout << std::format("Day 1 Part 2 Result: {}\n", Day1::Solution::part_2(input));
            break;
        case 2:
            std::cout
                    << std::format("Day 2 Part 1 Result: {}\n", Day2::Solution::part_1(input, Day2::Draw{12, 14, 13}));
            std::cout << std::format("Day 2 Part 2 Result: {}\n", Day2::Solution::part_2(input));
            break;
        default:
            std::cout << "Out of range [1-24] or not implemented" << "\n";
            break;

    }
}
