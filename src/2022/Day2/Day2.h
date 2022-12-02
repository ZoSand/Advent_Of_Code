//
// Created by ZoSand on 02/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY2_H
#define ADVENTOFCODE_GLOBAL_DAY2_H

#include <vector>
#include <tuple>
#include "../../Shared/Solution.h"

namespace AOC::Y2022
{
    class Day2 : public AOC::Shared::Solution
    {
    private:
        std::vector<std::tuple<char, char>> m_input;
    public:

        explicit Day2(std::string inputPath);

        std::string SolvePart1() override;

        std::string SolvePart2() override;
    };
} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY2_H
