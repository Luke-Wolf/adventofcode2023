#include "day_1.h"
#include <vector>
#include <algorithm>
#include <format>
#include <sstream>

namespace Day1 {
    auto Solution::part_1(const std::string &Input) -> int32_t {
        return calculate_input(Input, Solution::part_1_calculate_line);
    }

    auto Solution::part_2(const std::string &Input) -> int32_t {
        return calculate_input(Input, Solution::part_2_calculate_line);
    }

    auto Solution::calculate_input(const std::string &Input, int32_t (*function)(const std::string &)) -> int32_t {
        std::stringstream stream{Input};

        int32_t result = 0;
        while (!stream.eof()) {
            std::string line;
            std::getline(stream, line);
            if (!line.empty()) {
                result += function(line);
            }
        }
        return result;
    }

    auto Solution::part_1_calculate_line(const std::string &Line) -> int32_t {
        std::vector<char> numbers = {};
        for (const auto &character: Line) {
            if (isdigit(character) != 0) {
                numbers.push_back(character);
            }
        }

        if (numbers.empty()) { throw std::invalid_argument("input does not contain numbers"); }

        return atoi(std::format("{}{}", numbers.front(), numbers.back()).c_str());
    }

    auto Solution::part_2_calculate_line(const std::string &Line) -> int32_t {
        const auto tokens = lex(Line);
        std::vector<int32_t> numbers = {};
        for (const auto &token: tokens) {
            if (token.type == TokenType::Number) {
                numbers.push_back(std::get<int32_t>(token.value));
            }
        }

        if (numbers.empty()) { throw std::invalid_argument("input does not contain numbers"); }

        return atoi(std::format("{}{}", numbers.front(), numbers.back()).c_str());
    }

    auto Solution::lex(const std::string &Input) -> std::vector<Token> {
        std::vector<Token> tokens = {};
        for (auto itr = Input.cbegin(); itr != Input.cend(); itr++) {
            if (isdigit(*itr) != 0) {
                tokens.push_back(Token{TokenType::Number, *itr - '0'});
            } else {
                if (*itr == 'o') {
                    auto tmp = itr + 1;
                    if (tmp != Input.cend() && *tmp == 'n') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'e') {
                            tokens.push_back(Token{TokenType::Number, 1});
                            //itr = tmp;
                            continue;
                        }
                    }
                } else if (*itr == 't') {
                    auto tmp = itr + 1;
                    if (tmp != Input.cend() && *tmp == 'w') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'o') {
                            tokens.push_back(Token{TokenType::Number, 2});
                            //itr = tmp;
                            continue;
                        }
                    } else if (tmp != Input.cend() && *tmp == 'h') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'r') {
                            tmp++;
                            if (tmp != Input.cend() && *tmp == 'e') {
                                tmp++;
                                if (tmp != Input.cend() && *tmp == 'e') {
                                    tokens.push_back(Token{TokenType::Number, 3});
                                    //itr = tmp;
                                    continue;
                                }
                            }
                        }
                    }
                } else if (*itr == 'f') {
                    auto tmp = itr + 1;
                    if (tmp != Input.cend() && *tmp == 'o') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'u') {
                            tmp++;
                            if (tmp != Input.cend() && *tmp == 'r') {
                                tokens.push_back(Token{TokenType::Number, 4});
//                                itr = tmp;
                                continue;
                            }
                        }
                    } else if (tmp != Input.cend() && *tmp == 'i') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'v') {
                            tmp++;
                            if (tmp != Input.cend() && *tmp == 'e') {
                                tokens.push_back(Token{TokenType::Number, 5});
//                                itr = tmp;
                                continue;
                            }
                        }
                    }
                } else if (*itr == 's') {
                    auto tmp = itr + 1;
                    if (tmp != Input.cend() && *tmp == 'i') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'x') {
                            tokens.push_back(Token{TokenType::Number, 6});
//                            itr = tmp;
                            continue;
                        }
                    } else if (tmp != Input.cend() && *tmp == 'e') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'v') {
                            tmp++;
                            if (tmp != Input.cend() && *tmp == 'e') {
                                tmp++;
                                if (tmp != Input.cend() && *tmp == 'n') {
                                    tokens.push_back(Token{TokenType::Number, 7});
//                                    itr = tmp;
                                    continue;
                                }
                            }
                        }
                    }
                } else if (*itr == 'e') {
                    auto tmp = itr + 1;
                    if (tmp != Input.cend() && *tmp == 'i') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'g') {
                            tmp++;
                            if (tmp != Input.cend() && *tmp == 'h') {
                                tmp++;
                                if (tmp != Input.cend() && *tmp == 't') {
                                    tokens.push_back(Token{TokenType::Number, 8});
//                                    itr = tmp;
                                    continue;
                                }
                            }
                        }
                    }
                } else if (*itr == 'n') {
                    auto tmp = itr + 1;
                    if (tmp != Input.cend() && *tmp == 'i') {
                        tmp++;
                        if (tmp != Input.cend() && *tmp == 'n') {
                            tmp++;
                            if (tmp != Input.cend() && *tmp == 'e') {
                                tokens.push_back(Token{TokenType::Number, 9});
//                                itr = tmp;
                                continue;
                            }
                        }
                    }
                }
                tokens.push_back(Token{TokenType::Character, *itr});
            }
        }
        return tokens;
    }
}