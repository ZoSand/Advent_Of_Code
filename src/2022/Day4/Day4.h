//
// Created by ZoSand on 04/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY4_H
#define ADVENTOFCODE_GLOBAL_DAY4_H

#include <vector>
#include "../../Shared/Solution.h"

namespace AOC::Y2022 {

    class Day4 : public AOC::Shared::Solution {
    private:
        std::vector<std::string> m_input;
    public:
        explicit Day4(std::string inputPath);

        std::string SolvePart1() override;

        std::string SolvePart2() override;
    };

} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY4_H
