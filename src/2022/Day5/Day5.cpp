//
// Created by ZoSand on 05/12/2022.
//

#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include "Day5.h"

namespace AOC::Y2022
{
    Day5::Day5(std::string inputPath)
            : Solution("2022: Day5", std::move(inputPath))
    {
        std::ifstream file(m_inputPath);
        std::string line;

        std::vector<std::string> lines;

        while (std::getline(file, line))
        {
            lines.push_back(line);
        }

        m_crates.resize(9);

        for (;;)
        {
            if (lines[1].empty())
            {
                lines.erase(lines.begin(), lines.begin() + 2);
                break;
            }

            //TODO: parse crates

            //crate descriptive is [X] and crate position is the position of X in the line divided by 4
            //example:
            //    [C]         [Q]         [V]
            //    [D]         [D] [S]     [M] [Z]
            //    [G]     [P] [W] [M]     [C] [G]
            //    [F]     [Z] [C] [D] [P] [S] [W]
            //[P] [L]     [C] [V] [W] [W] [H] [L]
            //[G] [B] [V] [R] [L] [N] [G] [P] [F]
            //[R] [T] [S] [S] [S] [T] [D] [L] [P]
            //[N] [J] [M] [L] [P] [C] [H] [Z] [R]

            std::size_t cratePosition = 0;

            while (cratePosition < lines[0].size())
            {
                if (lines[0][cratePosition] == '[')
                {
                    m_crates[cratePosition / 4].push_back(lines[0][cratePosition + 1]);
                }

                cratePosition += 4;
            }

            lines.erase(lines.begin());
        }

        for (auto &vecLine: lines)
        {
            std::string discard;
            int x, y, z;
            std::istringstream iss(vecLine);
            if (vecLine.empty())
            {
                continue;
            }
            iss >> discard >> x >> discard >> y >> discard >> z;
            m_instructions.emplace_back(x, y, z);
        }

        //inverse each pile of crates
        //each pile is registered backwards
        for (auto &cratePile: m_crates)
        {
            std::reverse(cratePile.begin(), cratePile.end());
        }

        file.close();
    }

    std::string Day5::SolvePart1()
    {
        std::string result;

        //foreach instruction
        for (auto &instruction: m_instructions)
        {
            int cratesToMove = std::get<0>(instruction);
            int fromColumn = std::get<1>(instruction) - 1;
            int toColumn = std::get<2>(instruction) - 1;

            //print instructions
            std::cout << "Move " << cratesToMove << " crates from column " << fromColumn << " to column " << toColumn
                              << std::endl;

            //move cratesToMove crates from fromColumn to toColumn
            for (int i = 0; i < cratesToMove; i++)
            {
                m_crates.at(toColumn).push_back(m_crates.at(fromColumn).back());
                m_crates.at(fromColumn).pop_back();
            }
        }

        //get last crate in each column
        for (auto &column: m_crates)
        {
            //if empty, continue
            if (column.empty())
            {
                continue;
            }
            result += column.back();
        }
        return result;
    }

    std::string Day5::SolvePart2()
    {
        return "std::string()";
    }
} // AOC::Y2022