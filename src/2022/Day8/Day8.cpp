//
// Created by ZoSand on 09/12/2022.
//

#include "Day8.h"

#include <fstream>
#include <tuple>

namespace AOC::Y2022
{
	bool Day8::IsVisible(
			std::size_t x,
			std::size_t y
	                    )
	{
		std::vector<std::tuple<std::size_t, std::size_t>> directions
				{
						{ 0,  1 },
						{ 1,  0 },
						{ 0,  -1 },
						{ -1, 0 }
				};

		for (const auto &[dx, dy]: directions)
		{
			std::size_t currentX = x;
			std::size_t currentY = y;
			int treeHeight = m_input[x][y];

			while (true)
			{
				currentX += dx;
				currentY += dy;

				if (currentX >= m_input.size() || currentY >= m_input[0].size()
						|| currentX < 0 || currentY < 0)
				{
					return true;
				}

				if (m_input[currentX][currentY] >= treeHeight)
				{
					break;
				}
			}
		}
		return false;
	}

	Day8::Day8(std::string inputPath)
			: Solution("2022: Day8", std::move(inputPath))
	{
		std::ifstream inputFile(m_inputPath);
		std::string line;
		while (std::getline(inputFile, line))
		{
			std::vector<int> numbers;
			for (char &c: line)
			{
				if (c >= '0' && c <= '9')
				{
					numbers.push_back(c - '0');
				}
			}
			m_input.push_back(numbers);
		}

		inputFile.close();
	}

	std::string Day8::SolvePart1()
	{
		std::size_t visibleCount = 0;
		//foreach input
		for (std::size_t i = 0; i < m_input.size(); i++)
		{
			//foreach number in input
			for (std::size_t j = 0; j < m_input[i].size(); j++)
			{

				IsVisible(i, j) ? visibleCount++ : visibleCount;
			}
		}

		return std::to_string(visibleCount);
	}

	std::string Day8::SolvePart2()
	{
		return "Not implemented yet";
	}
} // AOC::Y2022