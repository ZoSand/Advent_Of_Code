//
// Created by Etudiant1 on 02/12/2022.
//

#ifndef ADVENTOFCODE_GLOBAL_OUTPUTTABLE_H
#define ADVENTOFCODE_GLOBAL_OUTPUTTABLE_H

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

namespace AOC::Shared
{
    class OutputTable
    {
    private:
        std::string m_columnNames[3];
        int m_columnWidths[3];

        std::vector<std::tuple<std::string, std::string>> m_rows;

        std::string m_tableName;

    public:
        explicit OutputTable(std::string _tableName);

        void AddRow(std::string solution1, std::string solution2);

        friend std::ostream &operator<<(std::ostream &os, const OutputTable &table);
    };

} // AOC::Shared

#endif //ADVENTOFCODE_GLOBAL_OUTPUTTABLE_H
