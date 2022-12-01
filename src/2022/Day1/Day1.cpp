//
// Created by ZoSand on 01/12/2022.
//

#include <fstream>
#include <sstream>
#include "Day1.h"

namespace AOC::Y2022
{
    Day1::Day1(std::string _inputPath)
            : Solution("2022: Day1", std::move(_inputPath))
    {
        std::ifstream elvesInventories(m_inputPath);
        int elvesInventoryPreviousIndex = 0;
        int elvesInventoryIndex = 0;
        int thisElfInventoryValue = 0;

        //parse elves inventories into strings by double newline
        std::string elvesInventory;
        while (std::getline(elvesInventories, elvesInventory))
        {
            std::istringstream elvesInventoryStream(elvesInventory);
            std::string elvesInventoryLine;

            // check if double newline
            if (elvesInventory.empty())
            {
                elvesInventoryIndex++;
                continue;
            }

            //if previous index is different from current index, push value in vector and reset value
            if (elvesInventoryPreviousIndex != elvesInventoryIndex)
            {
                m_elvesInventory.push_back(thisElfInventoryValue);
                thisElfInventoryValue = 0;
                elvesInventoryPreviousIndex = elvesInventoryIndex;
            }

            // parse elves inventory line into int and add to value
            while (std::getline(elvesInventoryStream, elvesInventoryLine))
            {
                thisElfInventoryValue += std::stoi(elvesInventoryLine);
            }
        }

        // push last value
        m_elvesInventory.push_back(thisElfInventoryValue);

        //close file
        elvesInventories.close();
    }

    std::string Day1::SolvePart1()
    {
        //get highest value in vector
        int highestValue = 0;
        for (int elvesInventory : m_elvesInventory)
        {
            if (elvesInventory > highestValue)
            {
                highestValue = elvesInventory;
            }
        }
        return std::to_string(highestValue);
    }

    std::string Day1::SolvePart2()
    {
        //find top 3 values in vector
        int highestValue = 0;
        int secondHighestValue = 0;
        int thirdHighestValue = 0;

        for (std::size_t elvesInventory : m_elvesInventory)
        {
            if (elvesInventory > highestValue)
            {
                thirdHighestValue = secondHighestValue;
                secondHighestValue = highestValue;
                highestValue = elvesInventory;
            }
            else if (elvesInventory > secondHighestValue)
            {
                thirdHighestValue = secondHighestValue;
                secondHighestValue = elvesInventory;
            }
            else if (elvesInventory > thirdHighestValue)
            {
                thirdHighestValue = elvesInventory;
            }
        }

        return std::to_string(highestValue + secondHighestValue + thirdHighestValue);
    }
} // AOC::Y2022