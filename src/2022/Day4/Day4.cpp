//
// Created by ZoSand on 04/12/2022.
//

#include <fstream>
#include "Day4.h"

namespace AOC::Y2022 {

    Day4::Day4(std::string inputPath) : Solution("2022: Day4", std::move(inputPath)) {
        //open file
        std::ifstream file(m_inputPath);

        //check if file is open
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + m_inputPath);
        }

        //read file
        std::string line;
        while (std::getline(file, line)) {
            m_input.push_back(line);
        }

        //close file
        file.close();
    }

    std::string Day4::SolvePart1() {
        //foreach line in input, check if both ranges of form i-j overlaps
        //if so, count++
        //return count
        std::size_t count = 0;
        for (const auto & i : m_input) {
                //get ranges
                //Two ranges are separated by a comma
                std::string range1 = i.substr(0, i.find(','));
                std::string range2 = i.substr(i.find(',') + 1);

                //get min and max of range1
                int min1 = std::stoi(range1.substr(0, range1.find('-')));
                int max1 = std::stoi(range1.substr(range1.find('-') + 1));

                //get min and max of range2
                int min2 = std::stoi(range2.substr(0, range2.find('-')));
                int max2 = std::stoi(range2.substr(range2.find('-') + 1));

                //check if ranges fully overlap
                if (min1 <= min2 && max1 >= max2
                || min2 <= min1 && max2 >= max1) {
                    count++;
                }
        }

        return std::to_string(count);
    }

    std::string Day4::SolvePart2() {
        //same as solve part 1 but check if ranges partially overlap
        std::size_t count = 0;
        for (const auto & i : m_input) {
            //get ranges
            //Two ranges are separated by a comma
            std::string range1 = i.substr(0, i.find(','));
            std::string range2 = i.substr(i.find(',') + 1);

            //get min and max of range1
            int min1 = std::stoi(range1.substr(0, range1.find('-')));
            int max1 = std::stoi(range1.substr(range1.find('-') + 1));

            //get min and max of range2
            int min2 = std::stoi(range2.substr(0, range2.find('-')));
            int max2 = std::stoi(range2.substr(range2.find('-') + 1));

            //check if ranges partially overlap
            if (min1 <= min2 && max1 >= min2
            || min2 <= min1 && max2 >= min1) {
                count++;
            }
        }

        return std::to_string(count);
    }

} // AOC::Y2022