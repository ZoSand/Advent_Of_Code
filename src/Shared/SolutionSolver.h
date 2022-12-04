//
// Created by ZoSand on 01/12/2022.
//

#ifndef ADVENT_OF_CODE_SOLUTIONSOLVER_H
#define ADVENT_OF_CODE_SOLUTIONSOLVER_H

#include <vector>
#include <tuple>
#include "Solution.h"
#include "OutputTable.h"

namespace AOC::Shared
{
    class SolutionSolver
    {
    private:
        std::vector<Solution *> m_solutions;
        std::vector<std::tuple<std::string, std::string>> m_results;

        OutputTable m_outputTable;

    public:
        explicit SolutionSolver(const std::string &year);
        ~SolutionSolver();

        [[maybe_unused]] void AddSolution(Solution *solution);

        [[maybe_unused]] void SolveAll();
    };

} // AOC::Shared

#endif //ADVENT_OF_CODE_SOLUTIONSOLVER_H
