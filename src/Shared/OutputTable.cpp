//
// Created by Etudiant1 on 02/12/2022.
//

#include <iomanip>
#include "OutputTable.h"

namespace AOC::Shared
{
    OutputTable::OutputTable(std::string _tableName)
    {
        m_tableName = std::move(_tableName);
        m_columnNames[0] = "Day";
        m_columnNames[1] = "Part 1";
        m_columnNames[2] = "Part 2";

        m_columnWidths[0] = 5;
        m_columnWidths[1] = 8;
        m_columnWidths[2] = 8;

        m_rows.reserve(25);
    }

    void OutputTable::AddRow(std::string solution1, std::string solution2)
    {
        m_columnWidths[1] = std::max(m_columnWidths[1], static_cast<int>(solution1.length() + 2));
        m_columnWidths[2] = std::max(m_columnWidths[2], static_cast<int>(solution2.length() + 2));
        m_rows.emplace_back(std::move(solution1), std::move(solution2));
    }

    std::ostream &operator<<(std::ostream &os, const OutputTable &table)
    {
        os << table.m_tableName << std::endl;
        os << "+" << std::setfill('-') << std::setw(table.m_columnWidths[0] + 1)
           << "+" << std::setfill('-') << std::setw(table.m_columnWidths[1] + 1)
           << "+" << std::setfill('-') << std::setw(table.m_columnWidths[2] + 1)
           << "+" << std::endl;

        os << "| " << std::setfill(' ') << std::setw(table.m_columnWidths[0] - 2) << table.m_columnNames[0] << " "
           << "| " << std::setfill(' ') << std::setw(table.m_columnWidths[1] - 2) << table.m_columnNames[1] << " "
           << "| " << std::setfill(' ') << std::setw(table.m_columnWidths[2] - 2) << table.m_columnNames[2] << " "
           << "|" << std::endl;

        os << "+" << std::setfill('-') << std::setw(table.m_columnWidths[0] + 1)
           << "+" << std::setfill('-') << std::setw(table.m_columnWidths[1] + 1)
           << "+" << std::setfill('-') << std::setw(table.m_columnWidths[2] + 1)
           << "+" << std::endl;

        for (int i = 0; i < table.m_rows.size(); i++)
        {
            os << "| " << std::setfill(' ') << std::setw(table.m_columnWidths[0] - 2) << i + 1 << " "
               << "| " << std::setfill(' ') << std::setw(table.m_columnWidths[1] - 2) << std::get<0>(table.m_rows[i]) << " "
               << "| " << std::setfill(' ') << std::setw(table.m_columnWidths[2] - 2) << std::get<1>(table.m_rows[i]) << " "
               << "|" << std::endl;
        }

        os << "+" << std::setfill('-') << std::setw(table.m_columnWidths[0] + 1)
           << "+" << std::setfill('-') << std::setw(table.m_columnWidths[1] + 1)
           << "+" << std::setfill('-') << std::setw(table.m_columnWidths[2] + 1)
           << "+" << std::endl;

        return os;
    }
}
