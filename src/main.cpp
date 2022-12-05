#include "2022/2022.h"
#include "Shared/SolutionSolver.h"

int main()
{
    //AOC::Shared::SolutionSolver solver2021;
    AOC::Shared::SolutionSolver solver("2022");

    solver.AddSolution(new AOC::Y2022::Day1("./2022/Day1/input.txt"));
    solver.AddSolution(new AOC::Y2022::Day2("./2022/Day2/input.txt"));
    solver.AddSolution(new AOC::Y2022::Day3("./2022/Day3/input.txt"));
    solver.AddSolution(new AOC::Y2022::Day4("./2022/Day4/input.txt"));
    solver.AddSolution(new AOC::Y2022::Day5("./2022/Day5/input.txt"));
    solver.SolveAll();

    return 0;
}
