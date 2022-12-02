cmake_minimum_required(VERSION 3.24)
project(Advent_Of_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(Advent_Of_Code
        Shared/Solution.h
        Shared/SolutionSolver.cpp Shared/SolutionSolver.h

        2022/2022.h
        2022/Day1/Day1.cpp 2022/Day1/Day1.h
        2022/Day2/Day2.cpp 2022/Day2/Day2.h
        main.cpp )

install(TARGETS Advent_Of_Code DESTINATION bin)