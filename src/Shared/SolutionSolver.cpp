//
// Created by ZoSand on 01/12/2022.
//

#include "SolutionSolver.h"

namespace AOC::Shared
{
    [[maybe_unused]] void SolutionSolver::SolveAll()
    {
        for (auto solution : m_solutions)
        {
            solution->SolveAll();
        }

    }

    [[maybe_unused]] void SolutionSolver::AddSolution(Solution *solution)
    {
        m_solutions.push_back(solution);
    }
} // AOC::Shared