#ifndef ADVENTOFCODE2023_DAY_1_H
#define ADVENTOFCODE2023_DAY_1_H

#include <string>
#include <cstdint>
#include <variant>
#include <vector>

namespace Day1 {
    enum class TokenType {
        Character,
        Number
    };

    /**
     * Represents a basic Lexer Token
     */
    class Token {
    public:
        TokenType type;
        std::variant<int32_t, char> value;
    };

    class Solution {
    public:

        /**
         * Find the First and Last Digit in each line of an input string
         * combine them together to form a single two digit number and
         * then add all of the numbers formed by the lines together
         * @param Input a multiline string containing digits [0-9]
         * @return the sum of the numeric value of the combination of the first and
         * last digit in each line
         * @throw std::invalid_argument if Input does not contain any numbers
         */
        auto static part_1(const std::string &Input) -> int32_t;

        /**
         * Find the First and Last Digit in each line of an input string
         * combine them together to form a single two digit number and
         * then add all of the numbers formed by the lines together
         *
         * Additionally considers spelled out numbers one - nine as
         * valid digits
         * @param Input a multiline string containing digits [0-9] and [one-nine]
         * @return the sum of the numeric value of the combination of the first and
         * last digit in each line
         * @throw std::invalid_argument if Input does not contain any numbers
         */
        auto static part_2(const std::string &Input) -> int32_t;

    private:
        auto static calculate_input(const std::string &Input, int32_t (*function)(const std::string &)) -> int32_t;

        auto static part_1_calculate_line(const std::string &Line) -> int32_t;

        auto static part_2_calculate_line(const std::string &Line) -> int32_t;

        auto static lex(const std::string &Input) -> std::vector<Token>;
    };
}

#endif //ADVENTOFCODE2023_DAY_1_H
