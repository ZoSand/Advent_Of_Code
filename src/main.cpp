#include "2022/2022.h"
#include "Shared/SolutionSolver.h"

int main()
{
    AOC::Shared::SolutionSolver solver;
    solver.AddSolution(new AOC::Y2022::Day1("./2022/Day1/input.txt"));
    solver.SolveAll();
    return 0;
}
