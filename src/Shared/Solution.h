//
// Created by ZoSand on 01/12/2022.
//

#ifndef ADVENT_OF_CODE_SOLUTION_H
#define ADVENT_OF_CODE_SOLUTION_H

#include <string>
#include <iostream>

namespace AOC::Shared
{

    class [[maybe_unused]] Solution
    {
    protected:
        std::string m_inputPath;
        std::string m_name;
    public:
        Solution() = delete;

        explicit Solution(std::string _name, std::string _inputPath)
                : m_name(std::move(_name))
                , m_inputPath(std::move(_inputPath))
        {};

        [[maybe_unused]] void SolveAll()
        {
            std::cout << m_name << ", Part 1: " << SolvePart1() << std::endl;
            std::cout << m_name << ", Part 2: " << SolvePart2() << std::endl;
        };

        [[maybe_unused]] virtual std::string SolvePart1() = 0;

        [[maybe_unused]] virtual std::string SolvePart2() = 0;
    };

} // AOC::Shared

#endif //ADVENT_OF_CODE_SOLUTION_H
