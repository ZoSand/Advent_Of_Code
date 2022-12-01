//
// Created by ZoSand on 01/12/2022.
//

#ifndef ADVENT_OF_CODE_SOLUTIONSOLVER_H
#define ADVENT_OF_CODE_SOLUTIONSOLVER_H

#include <vector>
#include "Solution.h"

namespace AOC::Shared
{
    class SolutionSolver
    {
    private:
        std::vector<Solution *> m_solutions;

    public:
        [[maybe_unused]] void AddSolution(Solution *solution);

        [[maybe_unused]] void SolveAll();
    };

} // AOC::Shared

#endif //ADVENT_OF_CODE_SOLUTIONSOLVER_H
