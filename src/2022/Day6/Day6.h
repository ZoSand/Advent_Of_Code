//
// Created by ZoSand on 06/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY6_H
#define ADVENTOFCODE_GLOBAL_DAY6_H

#include "../../Shared/Solution.h"

namespace AOC::Y2022
{

    class Day6 : public Shared::Solution
    {
        std::string m_signalData;
    public:
        Day6(std::string inputPath);

        std::string SolvePart1() override;

        std::string SolvePart2() override;
    };

} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY6_H
