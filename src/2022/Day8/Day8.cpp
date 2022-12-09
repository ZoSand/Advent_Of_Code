//
// Created by ZoSand on 09/12/2022.
//

#include "Day8.h"

#include <fstream>
#include <tuple>

namespace AOC::Y2022
{
	bool Day8::IsVisible(
			int x,
			int y
	                    )
	{
		std::vector<std::tuple<int, int>> directions
				{
						{ 0,  1 },
						{ 1,  0 },
						{ 0,  -1 },
						{ -1, 0 }
				};

		for (const auto &[dx, dy]: directions)
		{
			int currentX = x;
			int currentY = y;
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

	std::size_t Day8::GetScenicScore(
			int x,
			int y
	                                )
	{
		std::vector<std::tuple<int, int>> directions
				{
						{ 0,  1 },
						{ 1,  0 },
						{ 0,  -1 },
						{ -1, 0 }
				};

		std::size_t score = 1;
		for (auto &[dx, dy]: directions)
		{
			int currentX = x;
			int currentY = y;
			int treeHeight = m_input[x][y];
			std::size_t viewingDistance = 0;

			while (true)
			{
				currentX += dx;
				currentY += dy;

				if (currentX >= m_input.size() || currentY >= m_input[0].size()
						|| currentX < 0 || currentY < 0)
				{
					break;
				}

				viewingDistance++;

				if (m_input[currentX][currentY] >= treeHeight)
				{
					break;
				}
			}
			if (viewingDistance > 0)
			{
				score *= viewingDistance;
			}
		}
		return score;
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
		for (int i = 0; i < m_input.size(); i++)
		{
			//foreach number in input
			for (int j = 0; j < m_input[i].size(); j++)
			{

				IsVisible(i, j) ? visibleCount++ : visibleCount;
			}
		}

		return std::to_string(visibleCount);
	}

	std::string Day8::SolvePart2()
	{
		std::size_t bestScore = 0;

		for (int i = 0; i < m_input.size(); i++)
		{
			for (int j = 0; j < m_input[i].size(); j++)
			{
				std::size_t treeScore = GetScenicScore(i, j);
				std::cout << treeScore << std::endl;
				if (treeScore > bestScore)
				{
					bestScore = treeScore;
				}
			}
		}

		return std::to_string(bestScore);
	}
} // AOC::Y2022