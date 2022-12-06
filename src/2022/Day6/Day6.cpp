//
// Created by ZoSand on 06/12/2022.
//

#include "Day6.h"
#include <fstream>
#include <set>

namespace AOC::Y2022
{
    Day6::Day6(std::string inputPath)
            : Solution("2022: Day6", std::move(inputPath))
    {
        //open file and read all chars as a string
        std::fstream file(m_inputPath);
        std::string line;

        while (std::getline(file, line))
        {
            m_signalData += line;
        }

        file.close();
    }

    std::string Day6::SolvePart1()
    {
        //find the first sequence of 4 different chars
        std::size_t firstSequence = 0;
        for (std::size_t i = 0; i < m_signalData.size() - 3; i++)
        {
            std::string sequence = m_signalData.substr(i, 4);
            std::set<char> charSet(sequence.begin(), sequence.end());
            if (charSet.size() == 4)
            {
                firstSequence = i + 4;
                break;
            }
        }
        return std::to_string(firstSequence);
    }

    std::string Day6::SolvePart2()
    {
        //same as part 1 but with 14 different chars
        std::size_t firstSequence = 0;
        for (std::size_t i = 0; i < m_signalData.size() - 13; i++)
        {
            std::string sequence = m_signalData.substr(i, 14);
            std::set<char> charSet(sequence.begin(), sequence.end());
            if (charSet.size() == 14)
            {
                firstSequence = i + 14;
                break;
            }
        }
        return std::to_string(firstSequence);
    }
} // AOC::Y2022