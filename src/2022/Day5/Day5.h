//
// Created by ZoSand on 05/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY5_H
#define ADVENTOFCODE_GLOBAL_DAY5_H

#include <vector>
#include "../../Shared/Solution.h"

namespace AOC::Y2022
{

    class Day5 : public AOC::Shared::Solution
    {
    private :
        std::vector<std::vector<char>> m_crates;
        std::vector<std::tuple<int, int, int>> m_instructions;

    public:
        explicit Day5(std::string inputPath);

        std::string SolvePart1() override;

        std::string SolvePart2() override;

    };

} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY5_H
