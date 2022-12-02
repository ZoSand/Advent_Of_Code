//
// Created by ZoSand on 02/12/2022.
//

#include <fstream>
#include "Day2.h"

namespace AOC::Y2022
{
    Day2::Day2(std::string inputPath)
            : Solution("2022: Day2", std::move(inputPath))
    {
        //open file at inputPath
        std::ifstream file(m_inputPath);

        //read file line by line
        std::string line;
        while (std::getline(file, line))
        {
            //parse line
            //split line in ' ' and get the first and second element
            std::string first = line.substr(0, line.find(' '));
            std::string second = line.substr(line.find(' ') + 1, line.end() - line.begin());

            //push pair in vector
            m_input.emplace_back(first[0], second[0]);
        }

        //close file
        file.close();
    }

    std::string Day2::SolvePart1()
    {
        int score = 0;

        //if first char is equal to second char, increment score by 3
        for (const auto &[first, second]: m_input)
        {
            switch (second)
            {
                case 'X':
                    score += 1;
                    break;
                case 'Y':
                    score += 2;
                    break;
                case 'Z':
                    score += 3;
                    break;
                default:
                    throw std::runtime_error("Invalid input");
            }

            //calculate round score
            //draw
            if (first == second  - ('Z' - 'C'))
            {
                score += 3;
            }
            //defeat
            else if ((first == 'A' && second == 'Z')
                    || (first == 'B' && second == 'X')
                    || (first == 'C' && second == 'Y'))
            {
                score += 0;
            }
            //victory
            else
            {
                score += 6;
            }
        }

        return std::to_string(score);
    }

    std::string Day2::SolvePart2()
    {
        int score = 0;

        //if second char is 'X', lose
        //if second char is 'Y', draw
        //if second char is 'Z', win
        for (const auto &[first, second]: m_input)
        {
            switch (second)
            {
                case 'X':
                    switch (first)
                    {
                        case 'A':
                            //we need to lose, so we need to play 'Z'
                            score += 3;
                            break;
                        case 'B':
                            //we need to lose, so we need to play 'X'
                            score += 1;
                            break;
                        case 'C':
                            //we need to lose, so we need to play 'Y'
                            score += 2;
                            break;
                        default:
                            throw std::runtime_error("Invalid input");
                    }
                    break;
                case 'Y':
                    switch (first)
                    {
                        case 'A':
                            //we need to draw, so we need to play 'X'
                            score += 1;
                            break;
                        case 'B':
                            //we need to draw, so we need to play 'Y'
                            score += 2;
                            break;
                        case 'C':
                            //we need to draw, so we need to play 'Z'
                            score += 3;
                            break;
                        default:
                            throw std::runtime_error("Invalid input");
                    }
                    score += 3;
                    break;
                case 'Z':
                    switch (first)
                    {
                        case 'A':
                            //we need to win, so we need to play 'Y'
                            score += 2;
                            break;
                        case 'B':
                            //we need to win, so we need to play 'Z'
                            score += 3;
                            break;
                        case 'C':
                            //we need to win, so we need to play 'X'
                            score += 1;
                            break;
                        default:
                            throw std::runtime_error("Invalid input");
                    }
                    score += 6;
                    break;
                default:
                    throw std::runtime_error("Invalid input");
            }
        }


        return std::to_string(score);
    }
} // AOC::Y2022