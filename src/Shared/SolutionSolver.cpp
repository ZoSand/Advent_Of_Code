//
// Created by ZoSand on 01/12/2022.
//

#include "SolutionSolver.h"

namespace AOC::Shared
{

    SolutionSolver::SolutionSolver(const std::string &year)
            : m_outputTable("Advent of Code " + year)
    {
        m_solutions.reserve(25);
        m_results.reserve(25);
    }

    [[maybe_unused]] void SolutionSolver::SolveAll()
    {
        for (auto solution: m_solutions)
        {
            m_outputTable.AddRow(solution->SolvePart1(), solution->SolvePart2());
        }

        std::cout << m_outputTable << std::endl;
    }

    [[maybe_unused]] void SolutionSolver::AddSolution(Solution *solution)
    {
        m_solutions.emplace_back(solution);
    }
} // AOC::Shared