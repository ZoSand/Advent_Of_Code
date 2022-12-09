//
// Created by ZoSand on 09/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY8_H
#define ADVENTOFCODE_GLOBAL_DAY8_H

#include <vector>
#include "../../Shared/Solution.h"

namespace AOC::Y2022
{

	class Day8
			: public Shared::Solution
	{
	private:
		std::vector<std::vector<int>> m_input;

	public:
		explicit Day8(std::string inputPath);

		std::string SolvePart1() override;

		std::string SolvePart2() override;

		bool IsVisible(
				int i,
				int j
		              );

		std::size_t GetScenicScore(
				int x,
				int y
		                          );
	};

} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY8_H
