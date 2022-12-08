#include "2022/2022.h"
#include "Shared/SolutionSolver.h"

int main()
{
    //TODO:precedent years
    AOC::Shared::SolutionSolver solver2022("2022");

    solver2022.AddSolution(new AOC::Y2022::Day1("./2022/Day1/input.txt"));
    solver2022.AddSolution(new AOC::Y2022::Day2("./2022/Day2/input.txt"));
    solver2022.AddSolution(new AOC::Y2022::Day3("./2022/Day3/input.txt"));
    solver2022.AddSolution(new AOC::Y2022::Day4("./2022/Day4/input.txt"));
    solver2022.AddSolution(new AOC::Y2022::Day5("./2022/Day5/input.txt"));
    solver2022.AddSolution(new AOC::Y2022::Day6("./2022/Day6/input.txt"));
	solver2022.AddSolution(new AOC::Y2022::Day7("./2022/Day7/input.txt"));
    solver2022.SolveAll();

    return 0;
}
