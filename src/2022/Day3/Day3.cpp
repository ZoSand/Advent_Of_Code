//
// Created by ZoSand on 04/12/2022.
//

#include <fstream>
#include <cstring>
#include "Day3.h"

namespace AOC::Y2022 {
    Day3::Day3(std::string inputPath)
            : Solution("2022: Day3", std::move(inputPath)) {
        //open file
        std::ifstream inputFile(m_inputPath);
        if (!inputFile.is_open()) {
            std::cout << "Failed to open file: " << m_inputPath << std::endl;
            return;
        }

        //read file
        std::string line;
        while (std::getline(inputFile, line)) {
            m_rucksacks.push_back(line);
        }

        //close file
        inputFile.close();
    }

    std::string Day3::SolvePart1() {
        std::size_t result = 0;

        //for each line, split in 2 equal length strings then find common characters
        for (const auto &rucksack: m_rucksacks) {
            //split in 2 equal length strings
            std::size_t halfLength = rucksack.length() / 2;
            std::string firstHalf = rucksack.substr(0, halfLength);
            std::string secondHalf = rucksack.substr(halfLength, halfLength);

            //find common characters
            for (char i: firstHalf) {
                if (secondHalf.find(i) != std::string::npos) {
                    result += m_priority.find(i) + 1;
                    break;
                }
            }
        }

        return std::to_string(result);
    }

    std::string Day3::SolvePart2() {
        std::size_t result = 0;
        for (int i = 0; i < m_rucksacks.size(); i += 3) {
           //foreach 3 strings, find common char between all strings
            for (char j: m_rucksacks[i]) {
                if (m_rucksacks[i + 1].find(j) != std::string::npos && m_rucksacks[i + 2].find(j) != std::string::npos) {
                    result += m_priority.find(j) + 1;
                    break;
                }
            }
        }
        return std::to_string(result);
    }
}
