//
// Created by ZoSand on 08/12/2022.
//

#include <fstream>
#include "Day7.h"

namespace AOC::Y2022
{
	void Day7::calculateSize(Day7::directory& directory)
	{
		for (auto &dir : directory.subDirectories)
		{
			calculateSize(dir.second);
			directory.size += dir.second.size;
		}
		for (auto &file : directory.files)
		{
			directory.size += file.second.size;
		}
	}

	std::size_t Day7::SumUpSizes(Day7::directory &directory1)
	{
		//foreach subdirectory in directory1 sum up the sizes if the size is less than 100000
		std::size_t sum = 0;
		for (auto &dir : directory1.subDirectories)
		{
			if (dir.second.size < 100000)
			{
				sum += dir.second.size;
			}
			sum += SumUpSizes(dir.second);
		}
		return sum;
	}

	Day7::Day7(std::string inputPath)
			: Shared::Solution("2022: Day7", std::move(inputPath))
	{
		std::fstream input(m_inputPath);
		std::string line;

		while (std::getline(input, line))
		{
			m_input.push_back(line);
		}

		root.name = "/";
		root.files = { };
		root.subDirectories = { };

		currentDirectory = &root;

		//construct input tree
		for (std::size_t i = 0; i < m_input.size(); i++)
		{
			auto &cmdLine = m_input[i];

			if (cmdLine.starts_with('$'))
			{
				//split line into command and argument
				std::string cmd = cmdLine.substr(2, 2);

				if (cmd == "cd")
				{
					std::string arg = cmdLine.substr(cmdLine.find_last_of(' ') + 1); //c
					if (arg == "/")
					{
						currentDirectory = &root;
					}
					else if (arg == "..")
					{
						currentDirectory = currentDirectory->parent;
					}
					else
					{
						//create directory if it doesn't exist
						if (currentDirectory->subDirectories.find(arg) == currentDirectory->subDirectories.end())
						{
							currentDirectory->subDirectories[arg] = directory();
							currentDirectory->subDirectories[arg].name = arg;
							currentDirectory->subDirectories[arg].parent = currentDirectory;
							currentDirectory->subDirectories[arg].files = { };
							currentDirectory->subDirectories[arg].subDirectories = { };
						}
						currentDirectory = &currentDirectory->subDirectories[arg];
					}
				}
				else if (cmd == "ls")
				{
					std::cout << "Listing directory " << currentDirectory->name << std::endl;
					while (i + 1 < m_input.size() && !m_input[i + 1].starts_with('$'))
					{
						if (m_input[i + 1].starts_with("dir"))
						{
							std::string arg = m_input[i + 1].substr(m_input[i + 1].find_last_of(' ') + 1);

							if (currentDirectory->subDirectories.find(arg) == currentDirectory->subDirectories.end())
							{
								currentDirectory->subDirectories[arg] = directory();
								currentDirectory->subDirectories[arg].name = arg;
								currentDirectory->subDirectories[arg].parent = currentDirectory;
								currentDirectory->subDirectories[arg].files = { };
								currentDirectory->subDirectories[arg].subDirectories = { };
							}
						}
						else
						{
							std::string arg = m_input[i + 1].substr(m_input[i + 1].find_last_of(' ') + 1);
							std::string fileSize = m_input[i + 1].substr(0, m_input[i + 1].find(' '));
							std::cout << "File: " << arg << " Size: " << fileSize << std::endl;

							if (currentDirectory->files.find(arg) == currentDirectory->files.end())
							{
								currentDirectory->files[arg] = file();
								currentDirectory->files[arg].name = arg;
								currentDirectory->files[arg].size = std::stoi(fileSize);
							}
						}
						i++;
					}
				}
			}
		}

		//calculate size of each directory
		for (auto &dir : root.subDirectories)
		{
			calculateSize(dir.second);
		}

		input.close();
	}

	std::string Day7::SolvePart1()
	{
		//sum up all directories size if they are bigger than 100000
		std::size_t size = SumUpSizes(root);
		return std::to_string(size);
	}

	std::string Day7::SolvePart2()
	{
		return "std::string()";
	}

} // AOC::Y2022