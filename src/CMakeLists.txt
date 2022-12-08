cmake_minimum_required(VERSION 3.24)
project(Advent_Of_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(Advent_Of_Code
        Shared/Solution.h
        Shared/SolutionSolver.cpp Shared/SolutionSolver.h
        Shared/OutputTable.cpp Shared/OutputTable.h


        2022/2022.h
        2022/Day1/Day1.cpp 2022/Day1/Day1.h
        2022/Day2/Day2.cpp 2022/Day2/Day2.h
        2022/Day3/Day3.cpp 2022/Day3/Day3.h
        2022/Day4/Day4.cpp 2022/Day4/Day4.h
        2022/Day5/Day5.cpp 2022/Day5/Day5.h
        2022/Day6/Day6.cpp 2022/Day6/Day6.h
        2022/Day7/Day7.cpp 2022/Day7/Day7.h

        main.cpp)

install(TARGETS Advent_Of_Code DESTINATION bin)