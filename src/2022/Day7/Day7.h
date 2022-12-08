//
// Created by ZoSand on 08/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_DAY7_H
#define ADVENTOFCODE_GLOBAL_DAY7_H

#include <vector>
#include <map>
#include "../../Shared/Solution.h"

namespace AOC::Y2022
{

	class Day7
			: public Shared::Solution
	{
	private:
		struct file
		{
			std::string name;
			std::size_t size;
		};

		struct directory
		{
			directory* parent;
			std::string name;
			std::map<std::string, file> files;
			std::size_t size;
			std::map<std::string, directory> subDirectories;
		};

		struct directory root;
		struct directory* currentDirectory;

		std::vector<std::string> m_input;

		void calculateSize(directory& directory1);

		std::size_t SumUpSizes(directory& directory1);
	public:
		explicit Day7(std::string inputPath);

		std::string SolvePart1() override;

		std::string SolvePart2() override;
	};

} // AOC::Y2022

#endif //ADVENTOFCODE_GLOBAL_DAY7_H
