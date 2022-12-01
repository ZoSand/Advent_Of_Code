//
// Created by ZoSand on 01/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY1_H
#define ADVENTOFCODE_GLOBAL_DAY1_H

#include "../../Shared/Solution.h"
#include <vector>
#include <map>

namespace AOC::Y2022
{

    class Day1
            : public AOC::Shared::Solution
    {
    private:
        std::vector<int> m_elvesInventory;
    public:
        Day1() = delete;

        explicit Day1(std::string _inputPath);

        std::string SolvePart1() override;

        std::string SolvePart2() override;
    };

} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY1_H
