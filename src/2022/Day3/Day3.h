//
// Created by ZoSand on 04/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY3_H
#define ADVENTOFCODE_GLOBAL_DAY3_H

#include <vector>
#include "../../Shared/Solution.h"

namespace AOC::Y2022 {
    class Day3 : public AOC::Shared::Solution {
    private :
        std::vector<std::string> m_rucksacks;
        std::string m_priority{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    public:
        explicit Day3(std::string inputFilePath);

        std::string SolvePart1() override;

        std::string SolvePart2() override;
    };
}

#endif //ADVENTOFCODE_GLOBAL_DAY3_H
